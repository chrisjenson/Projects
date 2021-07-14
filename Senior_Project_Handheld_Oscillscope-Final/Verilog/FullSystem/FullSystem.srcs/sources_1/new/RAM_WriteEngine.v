`timescale 1ns / 1ps

module RAM_WriteEngine(
    input clk,
    input reset,
    input onBit, //Use this to gate everything
    input ADC_SampleClock,
    //Write
    output reg [17:0] RAMW_WriteAddr, //Port A on RAM
    input [17:0] TriggeredAddress,
    output RAMW_En,
    //For Ring Buffer
    input reading,
    input [17:0] RAMR_ReadAddr,
    output reg TriggerWriteDone,
    input Triggered,
    input RAMReadDone,
    //DEBUG
    output reg DebugRAMFullFlag
    );
    
    
    /////////////////////////////////////////////////
    //Get negedge and posedge pulses
    wire ADC_SampleClock_posedge_pulse;
    wire ADC_SampleClock_negedge_pulse;
    reg ADC_SampleClock_WaingForSecondPosedge;
    wire ADC_SampleClock_secondposedge_pulse;
    
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
    
    always @(posedge clk)
    //Set signal
    begin
        if (reset)
        begin
            ADC_SampleClock_WaingForSecondPosedge <= 0;
        end
        else
        begin
            if (ADC_SampleClock_posedge_pulse)
            begin
                if (ADC_SampleClock_WaingForSecondPosedge)
                begin
                    ADC_SampleClock_WaingForSecondPosedge <= 0;
                end
                else
                begin
                    ADC_SampleClock_WaingForSecondPosedge <= 1;
                end
            end
        end
    end
    
    assign ADC_SampleClock_secondposedge_pulse = ADC_SampleClock_WaingForSecondPosedge & ADC_SampleClock_posedge_pulse;
    
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;
    assign ADC_SampleClock_negedge_pulse = ~ADC_SampleClock & ADC_SampleClock_p1;
    
    
    //End section
    ///////////////////////
    //Ring Buffer
    reg RingBufferInvalid;
    always @(*)
    //Input
    //Output
    begin
        RingBufferInvalid = ((reading) && (RAMW_WriteAddr == RAMR_ReadAddr));
    end
    //////////////////////////////////////////////////////////////    
    //Write Section
    assign RAMW_En = onBit & ADC_SampleClock_secondposedge_pulse  && !RingBufferInvalid; //DEBUG:Need to make this its own process and delay by one word..
    //!TriggerWriteDone^
    always @(posedge clk)
    begin
    //Signal Ram to write
    //Inputs
        //Reset
        //RAMW_En
    //Outputs
        //RAMW_WriteAddr
        if (reset)
        begin
            RAMW_WriteAddr <= 0;
        end
        else
        begin
            if (RAMW_En && !RingBufferInvalid ) //Write and enable and if (in reading state and write address == read address
            begin
                RAMW_WriteAddr <= RAMW_WriteAddr + 1;                
            end
        end
    end
    //////////////////////////////////////////////
    //Control TriggerWriteDone
    //Debug: Always @ (*)?????
    wire [17:0] TriggerStopAddr;
    assign TriggerStopAddr = TriggeredAddress + 131071; //131072??
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            TriggerWriteDone <= 0;
        end
        else
        begin
            if (Triggered)
                begin
                if (RAMW_WriteAddr == TriggerStopAddr)
                begin
                    TriggerWriteDone <= 1;
                end
                else if (RAMReadDone)
                begin
                //Get ready  for next trigger
                    TriggerWriteDone <= 0;
                end
            end
            else
            begin
                TriggerWriteDone <= 0;
            end
        end
    end

endmodule