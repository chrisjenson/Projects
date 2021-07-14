`timescale 1ns / 1ps


module RAM_ReadEngine(
    input clk,
    input reset,
    //Ram Read
    input SPI_ReadCommand,
    output reg [17:0] RAMR_ReadAddr, //Port B on RAM, current read location
    input [17:0] RAMR_Quantity,
    //input [17:0] RAMW_WriteAddr,
    input SlaveSel,
    
    //input onBit,
    //FIFO
    output reading,
    output reg DEBUGreading,
    output reg RAMReadDone,
    
    output reg FIFO_InRTS,
    input FIFO_InRTR,
    
    input Triggered,
    input [17:0] TriggeredAddress
    );
    reg [17:0] readRemaining;
    ///////////////////////////////////////////////////
    wire SPI_ReadCommandPosEdgePulse;
    wire SPI_ReadCommandNegEdgePulse;
    wire Triggered_PosEdgePulse;
    reg SPI_ReadCommand_p1;
    reg Triggered_p1;
    
    always @(posedge clk)
    begin
        SPI_ReadCommand_p1 <= SPI_ReadCommand;
        Triggered_p1 <= Triggered;
    end
    
    assign Triggered_PosEdgePulse = Triggered & ~Triggered_p1;
    assign SPI_ReadCommandPosEdgePulse = SPI_ReadCommand & ~SPI_ReadCommand_p1;
    assign SPI_ReadCommandNegEdgePulse = ~SPI_ReadCommand & SPI_ReadCommand_p1;
    ///////////////////////////////////////////////////
    
    
    wire FIFO_InXFC;
    assign FIFO_InXFC = FIFO_InRTS & FIFO_InRTR;
    assign reading = !RAMReadDone & SPI_ReadCommand; //&& onBit
    //assign DEBUGreading = reading;
    always @(posedge clk)
    begin
    //Determing if RAM should be reading data
    //Inputs
        //Reset
        //reading
        //FIFO_InXFC
    //Outputs
        //RAMR_ReadAddr
        //FIFO_InRTS
        if (reset)
        begin
            RAMR_ReadAddr <= 0;
            FIFO_InRTS <= 0;
            DEBUGreading <= 0;
        end
        else
        begin
            if (SlaveSel)
            //If SPI is done reading
            begin
                RAMR_ReadAddr <= 0; //If not reading, address is 0;
            end
            
            if (SPI_ReadCommandPosEdgePulse)
            begin
                RAMR_ReadAddr <= TriggeredAddress - (RAMR_Quantity/2);
            end
            else if (reading) //dont read when there is a positive edge pulse to set addresses 
            begin
                FIFO_InRTS <= 1;
                if (FIFO_InXFC)
                begin
                    RAMR_ReadAddr <= RAMR_ReadAddr + 1;
                end
            end
            else
            begin
                FIFO_InRTS <= 0;
            end
        end
        if (reading)
        begin
            DEBUGreading <= 1;
        end
    end
    always @(posedge clk)
    begin
    //Determing if RAM is done
    //Inputs
        //Reset
        //SlaveSelNegEdgePulse
        //FIFO_InXFC
    //Outputs
        //leftToRead - how many more data points will be going on
        //RAMReadDone - data read done
        if (reset)
        begin
            RAMReadDone <= 0;
            //readRemaining <= 0;
        end
        else
        begin
            if (SPI_ReadCommandPosEdgePulse)
            begin //Set initial value
                readRemaining <= RAMR_Quantity;
                RAMReadDone <= 0;
            end
            if (FIFO_InXFC)
            begin
                if (readRemaining == 0)
                begin
                    RAMReadDone <= 1;
                end
                else
                begin
                    readRemaining <= readRemaining - 1;
                end
            end
            if (SPI_ReadCommandNegEdgePulse)
            begin
                RAMReadDone <= 0;
            end
        end
        if (reading)
        begin
            if (SlaveSel)
            begin
                readRemaining <= 0;
                RAMReadDone <= 1;
            end
        end
    end
    
    
   
endmodule
