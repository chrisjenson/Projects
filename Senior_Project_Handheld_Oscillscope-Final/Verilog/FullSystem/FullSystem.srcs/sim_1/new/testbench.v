`timescale 1ns / 1ps

module testbench();
    //V2
    reg clk;
    reg reset;
    
    initial
    //Generate
    begin
        clk = 0;
        while(1)
        begin
            #5 clk = ~clk; //100MHZ clock. Board is capable of >450MHz
        end
    end
    
    initial
    //Initize reset
    begin
        reset = 1;
        #10 reset = 0;
    end
    
    reg SCLK;
    reg [1:0] SCLKCount;
    
    wire MISO;
    reg MOSI;
    reg SlaveSel;
    
    always @(posedge clk) 
    //Simluate Slave Clock
    begin
        if (!reset)
        begin
            if (!SlaveSel)
            begin
                SCLKCount <= SCLKCount + 1;
                if (SCLKCount == 2'b01)
                begin
                    #1 SCLK = ~SCLK;
                end
            end
        end
        else
        begin
            SCLKCount  <= 0;
            SCLK <= 1;
        end
    end
    ///////////////////////////////////////////////////
    reg [15:0] commandArray[9:0];
    initial
    begin  
        commandArray[0] = 16'b0000000000000000; //Do nothing
        commandArray[1] = 16'b0100011000000000; //Write 0 to reg 6, rising edge trigger
        commandArray[2] = 16'b0100011100001111; //Write 15 to reg 7, Threshold of 15
        commandArray[3] = 16'b0100100100000001; //Write 1 to reg 9, On
        commandArray[4] = 16'b0010111100000000; //read reg 15[0], triggered
        commandArray[5] = 16'b0110100011111111; //cmd = Read Ram, 1024 data points
        commandArray[6] = 16'b0100011100001111; //Write 15 to reg 7, Threshold of 15
        commandArray[7] = 16'b0100100100000001; //Write 1 to reg 9, On
        commandArray[8] = 16'b0010111100000000; //read reg 15[1], triggered
        commandArray[9] = 16'b0110100011111111; //cmd = Read Ram, 2048 data points
    end 
    
    reg [7:0] MCUStorage [524287:0];
    
    ////////////////////////////////////////////////////////
    parameter SSetup = 0, SWaitForTrigger = 1, SRead = 2, SIdle = 3;
    reg [3:0] State;
    reg SetupDone;
    reg Triggered;
    reg RamReadDone;
    
    always @(posedge clk)
    //State machine
    begin
        if (reset)
        begin
            State <= 0;
        end
        else
        begin
            if (SetupDone)
            begin
                State <= SWaitForTrigger;
            end
            else if (Triggered)
            begin
                State <= SRead;
            end
            else if (RamReadDone)
            begin
                State <= SIdle;
            end
            
            if (State == SIdle)
            begin
                //#300
                //State <= SWaitForTrigger;
            end
        end
    end
    
    reg [63:0] SPICommandIndex;
    reg CommandDonePulse;


    always @(posedge SCLK)
    begin
        //Drive SPICommandIndex
        if (reset)
        begin
        end
        else
        begin 
            if (CommandDonePulse)
            begin
                SPICommandIndex <= SPICommandIndex + 1;    
            end 
        end
    end
    
    //////////////////////////////////////////
    

    wire [2:0] SPICMD;
    wire [4:0] SPIParams;
    wire [7:0] SPIData;
    
    assign SPICMD = commandArray[SPICommandIndex][15:13];
    assign SPIParams = commandArray[SPICommandIndex][12:8];
    assign SPIData = commandArray[SPICommandIndex][7:0];
    
    reg [7:0] RegReadArray;
    reg [7:0] RegReadData;
    reg [63:0] BUFFER_InAmount;
    wire [63:0] RAMReadTransfers;
    always @(*)
    begin
        case (SPIParams)
            5'b00000:
            begin
                BUFFER_InAmount = 262144; //2^18 = max ram size
            end
            5'b00001:
            begin
                BUFFER_InAmount = 131072; //2^18
            end
            5'b00010:
            begin
                BUFFER_InAmount = 65536;
            end
            5'b00011:
            begin
                BUFFER_InAmount = 32768;
            end
            5'b00100:
            begin
                BUFFER_InAmount = 16384;
            end
            5'b00101:
            begin
                BUFFER_InAmount = 8192; //2^14
            end
            5'b00110:
            begin
                BUFFER_InAmount = 4096; 
            end
            5'b00111:
            begin
                BUFFER_InAmount = 2048;
            end
            5'b01000:
            begin
                BUFFER_InAmount = 1024;
            end
            5'b01001:
            begin
                BUFFER_InAmount = 512;
            end
            5'b01010:
            begin
                BUFFER_InAmount = 256;
            end
            5'b01011:
            begin
                BUFFER_InAmount = 128;
            end
            5'b01100:
            begin
                BUFFER_InAmount = 64;
            end
            5'b01101:
            begin
                BUFFER_InAmount = 32;
            end
            5'b01110:
            begin
                BUFFER_InAmount = 16;
            end
            5'b01111:
            begin
                BUFFER_InAmount = 8;
            end
            default:
            begin
                BUFFER_InAmount = 0;
            end
        endcase
    end    
    assign RAMReadTransfers = BUFFER_InAmount * 2; 
    
    reg [3:0] SPICounter;
    reg [2:0] RAMDataPointRead;
    reg [63:0] RAMReadsRemaining;
    reg [7:0] DataPoint;
    reg [7:0] DataPointDone;
    reg [2:0] RAMReadCounter;
    reg RAMReadCommand;

    
    //wire CommandDonePulsePosEdge;
    //wire CommandDonePulse_p1;
    //assign CommandDonePulsePosEdge = CommandDonePulse & ~CommandDonePulse_p1;
    
    initial
    begin
        RAMReadCommand <= 0;
        SPICounter <= 15;
        CommandDonePulse <= 0;
        SlaveSel <= 1;
        SPICommandIndex <= 1;
        RAMReadCounter <= 7;

        #20
        SlaveSel <= 0;
        
    end
    always @(posedge SCLK)    
    begin
        if (reset)
        begin
        
        end
        else
        begin
            if (CommandDonePulse)
            begin
                
                SlaveSel <= 1; 
                #500
                SlaveSel <= 0;                             
            end
        end
    end    
    
    reg RAMReadCommand_p1;
    wire RAMReadCommandPosEdgePulse;
    always @(posedge clk)
    begin
        RAMReadCommand_p1 <= RAMReadCommand;
        if (RAMReadCommandPosEdgePulse)
        begin
            RAMReadsRemaining <= RAMReadTransfers;
        end
        if (SPICMD == 3'b011)
        begin
            RAMReadCommand <= 1;
        end
        else
        begin
            RAMReadCommand <= 0;
        end
    end    
    assign RAMReadCommandPosEdgePulse = !RAMReadCommand_p1 && RAMReadCommand;
    
    always @(posedge SCLK)
    begin
        if (reset)
        begin
            SPICounter <= 15;
        end
        else
        begin
            if (CommandDonePulse)
            begin
                CommandDonePulse <= 0;
                SPICounter <= 15;
            end
            else
            begin
                if (!SlaveSel)
                begin
                    MOSI <= commandArray[SPICommandIndex][SPICounter];
                    SPICounter <= SPICounter - 1;
                    if (SPICMD == 3'b001) //Read
                    begin
                        if (SPICounter <= 7)
                        begin
                            RegReadArray[SPICounter] <= MISO;
                        end
                        if (SPICounter == 0)
                        begin
                            RegReadData <= RegReadArray; //DEBUG DOES THIS GET LAST VALUE?
                            SlaveSel <= 1; 
                            #30 SlaveSel <= 0; 
                        end
                        else
                        begin
                            RegReadData <= 0;
                        end
                    end
                    else
                    begin
                        RegReadArray <= 0;
                        RegReadData <= 0;
                    end
                    
                    if (SPICMD == 3'b011) //RAM Read
                    begin
                        RAMReadCounter <= RAMReadCounter - 1;
                        DataPoint[RAMReadCounter] <= MISO;
                        
                        if (RAMReadCounter == 0)
                        begin
                            MCUStorage[RAMReadsRemaining] <= {DataPoint, MISO}; //DEBUG, WILL THIS GET LAST ONE twice????
                            DataPointDone <= {DataPoint, MISO}; 
                            RAMReadCounter <= 7;
                            RAMReadsRemaining <= RAMReadsRemaining - 1;
                        end
                    end
                           
                end
                else //SS high
                begin
                    SPICounter <= 15;
                    RAMDataPointRead <= 7;
                    RegReadArray <= 0;
                    //
                    RegReadData <= 0;
                    DataPoint <= 0;
                    //CommandDonePulse <= 0;
                end
            end
        end
    end
    
    
    always @(posedge SCLK)
    begin
        //Drive SlaveSel
        if (reset)
        begin
            
        end
        else
        begin
            if (!SlaveSel)
            begin
                if (!CommandDonePulse)
                begin
                    if (SPICMD == 3'b001) //Read
                    begin
                        if (RegReadData == 1)//Triggered;
                        begin
                            //SlaveSel <= 1; //Go to next command
                            CommandDonePulse <= 1;
                        end
                    end     
                    else if (SPICMD == 3'b011) //Ram Read
                    begin       
                        if (RAMReadsRemaining == 0)
                        begin
                            //SlaveSel <= 1; //Next command
                            CommandDonePulse <= 1;
                        end
                    end
                    else if (SPICMD == 3'b010) //Write
                    begin
                    if (SPICounter == 0)
                        begin
                            //SlaveSel <= 1; //Next command
                            CommandDonePulse <= 1;
                        end
                    end
                    else //bad command
                    begin
                        //SlaveSel <= 1;
                        CommandDonePulse <= 1; 
                    end 
                end                
            end
            
        end
    end
    
    
    reg SimDataHigh;
    initial 
    begin
        SimDataHigh = 0;
        #100000000 SimDataHigh = 1;
    end
    Top u_Top(
        .clk(clk),
        .rst_(~reset),
        //SPI
        .MOSI_Raw(MOSI),
        .SlaveSel(SlaveSel),
        .SCLK_Raw(SCLK),
        .MISO(MISO),
        //ADC Interface
        //.ADC_InData(ADC_InData),
        .ADC_SampleClock(ADC_SampleClock),
        .SimDataHigh(SimDataHigh)
    );
endmodule
    
    //////////////////////////////////////////////////////
    
    
   // wire ADC_SampleClock; //Input from Timing Gen

    ////////////////////////////////////////////////////////////
    
    //SPI TB
    /*
    reg SCLK;
    reg [1:0] SCLKCount;
    
    reg MISO;
    reg MOSI;
    reg SlaveSel;
    
    wire [15:0] command;
    reg [3:0] index;
    reg commandDone;
    reg [5:0] commandNum;
    initial
    begin
        SlaveSel <= 1;
        SCLK = 1;
        SCLKCount = 0;
        index = 15;
    end
    
    initial 
    begin
        commandDone <= 0;
        commandNum <= 0;
    end
    
    initial
    begin  
        commandArray[0] = 16'b0000000000000000;
        commandArray[1] = 16'b0000000000000000;
        //commandArray[1] = 16'b0100011000000001; //trigger on falling edge
        commandArray[2] = 16'b0110110111111111; //cmd = Read Ram
        commandArray[3] = 16'b0000000000000000;                                      //If changing number of data points being read (1024) need to change OneZeroTwoFourCounter below
        //commandArray[4] = 16'b0110110111111111; //cmd = Read, params = 4, data = x
        //commandArray[5] = 16'b0110110111111111; //cmd = write, params = 4, data = 8'hF0
        commandArray[6] = 16'b0000000000000000;
        commandArray[7] = 16'b0000000000000000;
        

    end 
    
    always @(posedge clk) 
    //Simluate Slave Clock
    begin
        if (!reset)
        begin
            if (!SlaveSel)
            begin
                SCLKCount <= SCLKCount + 1;
                if (SCLKCount == 2'b01)
                begin
                    #1 SCLK = ~SCLK;
                end
            end
        end
    end
    
    initial 
    //Initialize
    begin
        #50 //Begin spi after 50
        SlaveSel <=0;
        reset <= 0;
    end
    
    always @(posedge clk)
    //If command finished, go to next command
    begin
        if (!reset)
        begin
        if (commandDone)
            begin
                commandDone <= 0;
                #100;
                if (commandNum == 3)
                begin
                 //   reset <= 1;
                 //   #10
                //    reset <= 0;
                end
                commandNum <= commandNum + 1;
                SlaveSel <= 0;
            end
        end
    end
    
    assign command = commandArray[commandNum];
    reg [6:0] OneTwentyEightCounter; //128
    reg [9:0] RAMReadCounter; //1024


    always @(posedge SCLK)
    //Simulates SPI Master
    //Inputs:
        //SlaveSel
        //Command
    //Outputs:
        //MOSI
        //Index (initial = 15)
    begin
        if (!reset)
        begin
            if (!SlaveSel)
            begin
                if (command[15:13] == 3'b011) //If RAM Read
                begin
                    MOSI <= command[index];
                    if (index == 0)
                    begin //For testing, read 1024 data values.
                        index <= 15;
                        if (RAMReadCounter == 31) //# TRANSFERS OF 16 sets OF DATA
                        begin
                            #40 //wait 40 after ram read is done
                            SlaveSel <= 1;
                            commandDone <= 1;
                            RAMReadCounter <= 0;
                        end
                        else
                        begin
                            RAMReadCounter <= RAMReadCounter + 1;
                        end
                    end
                    else
                    begin
                        index <= index - 1;
                    end
                end
                else if (command[15:13] == 3'b000)
                begin
                    //IDLE
                    #40 
                    SlaveSel <= 1;
                    commandDone <= 1;
                    index <= 15;
                    //commandNum <= 0;
                end
                else if ((command[15:13] == 3'b001) ||  (command[15:13] == 3'b010)) //REG READ/WRITE
                begin
                    MOSI <= command[index];
                    index <= index - 1;
                    if (index == 0)
                    begin
                        #40 
                        SlaveSel <= 1;
                       // commandNum <= commandNum + 1;
                        commandDone <= 1;
                        index <= 15;
                    end
                end
                else //IDLE
                begin
                     //Commands done... Idle
                    #40 
                    SlaveSel <= 1;
                    //commandDone <= 1;
                    index <= 15;
                    //commandNum <= 0;
                end
            end
            else
            //If SS is high
            begin
                MOSI <= 0;
                index <= 15;
                OneTwentyEightCounter <= 0;
                RAMReadCounter <= 0;

                //commandDone <= 1;
            end
        end
        else
        begin
            RAMReadCounter <= 0;
        end
    end
    */
    /*
     //Simulate data input on hardware
    wire [9:0] ADC_InData;
    
    DataSimulation u_DataSimulation(
        .ADC_SampleClock(ADC_SampleClock),
        .clk(clk),
        .reset(reset),
        .SimData(ADC_InData)
    );
    /////////////////////
    
    */
    





//`timescale 1ns / 1ps

//module testbench();
    
//    reg clk;
//    reg reset;
    
//    initial
//    //Generate
//    begin
//        clk = 0;
//        while(1)
//        begin
//            #5 clk = ~clk; //100MHZ clock. Board is capable of >450MHz
//        end
//    end
    
//    initial
//    //Initize reset
//    begin
//        reset = 1;
//        #10 reset = 0;
//    end
    
//    /////////////////////
//    //Initialize input Data
//    //Obsolete due to DataSimulation Module
//    /*
//    `define numInputs     (16384)
    
//    wire [9:0] stimInData; //
//    reg [13:0] stimInCount; //2^14 = 16384
//    reg [9:0] stimData [`numInputs-1:0];
    
//     assign stimInData = stimData[stimInCount];
    
//    integer i;
//    initial
//    begin
//        //Initialize with random data
//        for (i = 0; i < `numInputs; i = i + 1)
//        begin
//            stimData[i] = $random();
//        end
//    end
    
//    //End intialize data
//    ///////////////////////////////////
    
    
//    always @(posedge clk)
//    begin
//        if (reset)
//        begin
//            stimInCount <= 0;
//        end
//    end
    
//    always @(posedge ADC_SampleClock)
//    //After ADC Sampling, go to next adc input
//    //Inputs
//        //Reset
//    begin
//        if (reset)
//        begin
//            stimInCount <= 0;
//        end
//        else
//        begin
//            stimInCount <= stimInCount + 1;
//        end
//    end
//    */
    
//    wire ADC_SampleClock; //Input from Timing Gen

//    ////////////////////////////////////////////////////////////
//    //SPI TB
    
//    reg SCLK;
//    reg [1:0] SCLKCount;
    
//    reg MISO;
//    reg MOSI;
//    reg SlaveSel;

//    wire [15:0] command;
//    reg [3:0] index;
//    reg commandDone;
//    reg [5:0] commandNum;
//    reg [15:0] commandArray[4:0];
//    initial
//    begin
//        SlaveSel <= 1;
//        SCLK = 1;
//        SCLKCount = 0;
//        index = 15;
//    end
    
//    initial 
//    begin
//        commandDone <= 0;
//        commandNum <= 0;
//    end
    
//    initial
//    begin  
//        commandArray[0] = 16'b0000000000000000;
//        commandArray[1] = 16'b0000000000000000;
//        //commandArray[1] = 16'b0100011000000001; //trigger on falling edge
//        commandArray[2] = 16'b0110110111111111; //cmd = Read Ram
//        commandArray[3] = 16'b0000000000000000;                                      //If changing number of data points being read (1024) need to change OneZeroTwoFourCounter below
//        //commandArray[4] = 16'b0110110111111111; //cmd = Read, params = 4, data = x
//        //commandArray[5] = 16'b0110110111111111; //cmd = write, params = 4, data = 8'hF0
//        commandArray[6] = 16'b0000000000000000;
//        commandArray[7] = 16'b0000000000000000;
        

//    end 
    
//    always @(posedge clk) 
//    //Simluate Slave Clock
//    begin
//        if (!reset)
//        begin
//            if (!SlaveSel)
//            begin
//                SCLKCount <= SCLKCount + 1;
//                if (SCLKCount == 2'b01)
//                begin
//                    #1 SCLK = ~SCLK;
//                end
//            end
//        end
//    end
    
//    initial 
//    //Initialize
//    begin
//        #50 //Begin spi after 50
//        SlaveSel <=0;
//        reset <= 0;
//    end
    
//    always @(posedge clk)
//    //If command finished, go to next command
//    begin
//        if (!reset)
//        begin
//        if (commandDone)
//            begin
//                commandDone <= 0;
//                #100;
//                if (commandNum == 3)
//                begin
//                 //   reset <= 1;
//                 //   #10
//                //    reset <= 0;
//                end
//                commandNum <= commandNum + 1;
//                SlaveSel <= 0;
//            end
//        end
//    end
    
//    assign command = commandArray[commandNum];
//    reg [6:0] OneTwentyEightCounter; //128
//    reg [9:0] RAMReadCounter; //1024


//    always @(posedge SCLK)
//    //Simulates SPI Master
//    //Inputs:
//        //SlaveSel
//        //Command
//    //Outputs:
//        //MOSI
//        //Index (initial = 15)
//    begin
//        if (!reset)
//        begin
//            if (!SlaveSel)
//            begin
//                if (command[15:13] == 3'b011) //If RAM Read
//                begin
//                    MOSI <= command[index];
//                    if (index == 0)
//                    begin //For testing, read 1024 data values.
//                        index <= 15;
//                        if (RAMReadCounter == 31) //# TRANSFERS OF 16 sets OF DATA
//                        begin
//                            #40 //wait 40 after ram read is done
//                            SlaveSel <= 1;
//                            commandDone <= 1;
//                            RAMReadCounter <= 0;
//                        end
//                        else
//                        begin
//                            RAMReadCounter <= RAMReadCounter + 1;
//                        end
//                    end
//                    else
//                    begin
//                        index <= index - 1;
//                    end
//                end
//                else if (command[15:13] == 3'b000)
//                begin
//                    //IDLE
//                    #40 
//                    SlaveSel <= 1;
//                    commandDone <= 1;
//                    index <= 15;
//                    //commandNum <= 0;
//                end
//                else if ((command[15:13] == 3'b001) ||  (command[15:13] == 3'b010)) //REG READ/WRITE
//                begin
//                    MOSI <= command[index];
//                    index <= index - 1;
//                    if (index == 0)
//                    begin
//                        #40 
//                        SlaveSel <= 1;
//                       // commandNum <= commandNum + 1;
//                        commandDone <= 1;
//                        index <= 15;
//                    end
//                end
//                else //IDLE
//                begin
//                     //Commands done... Idle
//                    #40 
//                    SlaveSel <= 1;
//                    //commandDone <= 1;
//                    index <= 15;
//                    //commandNum <= 0;
//                end
//            end
//            else
//            //If SS is high
//            begin
//                MOSI <= 0;
//                index <= 15;
//                OneTwentyEightCounter <= 0;
//                RAMReadCounter <= 0;

//                //commandDone <= 1;
//            end
//        end
//        else
//        begin
//            RAMReadCounter <= 0;
//        end
//    end
    
//     //Simulate data input on hardware
//    wire [9:0] ADC_InData;
    
//    DataSimulation u_DataSimulation(
//        .ADC_SampleClock(ADC_SampleClock),
//        .clk(clk),
//        .reset(reset),
//        .SimData(ADC_InData)
//    );
//    /////////////////////
    
    
    
//    Top u_Top(
//        .clk(clk),
//        .rst_(~reset),
//        //SPI
//        .MOSI_Raw(MOSI),
//        .SlaveSel(SlaveSel),
//        .SCLK_Raw(SCLK),
//        //ADC Interface
//        //.ADC_InData(ADC_InData),
//        .ADC_SampleClock(ADC_SampleClock)
//    );
//endmodule
