`timescale 1ns / 1ps

module TriggerLogic(
        input clk,
        input reset,
       // input ADC_SampleClock,
        input ADC_SampleClock_posedge_pulse,
        input onBit,
        input RAMReadDone,
        
        input [7:0] TriggerType,
        input signed [7:0] TriggerThreshold,
        input signed [9:0] ADC_InData,

        output reg Triggered,
        input [17:0] WriteAddress,
        output reg [17:0] TriggeredAddress        
    );

    reg [7:0] TriggerThreshold_p1;
    reg [7:0] TriggerType_p1;
    
    wire getNewData;
    assign getNewData = ADC_SampleClock_posedge_pulse & onBit;
        
    reg [7:0] ADC_InData_p1;
    reg [18:0] TriggerWaitCounter;
    
    reg [7:0] ADC_InData_m1;
    reg [7:0] ADC_InData_m2;
    reg [7:0] ADC_InData_m3;
    reg [7:0] ADC_InData_m4;
    reg [7:0] ADC_InData_m5;
    reg [7:0] ADC_InData_m6;
    reg [7:0] ADCAvg1;
    reg [7:0] ADCAvg2;
    
    
    //assign triggered = 1;
    
    always @(posedge clk)
    //Gets delayed inputs
        //Inputs
            //Reset
            //RAMW_En
        //Outputs
            //ADC_InData_p1
            //TriggerType_p1
            //TriggerThreshold_p1
    begin
        if (reset)
        begin
            ADC_InData_p1 <= 0;
            TriggerType_p1 <= 0;
            TriggerThreshold_p1 <= 0;
        end
        else
        begin
            if (ADC_SampleClock_posedge_pulse)
            begin //New input
                ADC_InData_m1 <= ADC_InData;
                ADC_InData_m2 <= ADC_InData_m1;
                ADC_InData_m3 <= ADC_InData_m2;
                ADC_InData_m4 <= ADC_InData_m3;
                ADC_InData_m5 <= ADC_InData_m4;
                ADC_InData_m6 <= ADC_InData_m5;
                
               ADCAvg1 <= (ADC_InData_m1 + ADC_InData_m2 + ADC_InData_m3 + ADC_InData_m4)/4;
               ADCAvg2 <= (ADC_InData_m3 + ADC_InData_m4 + ADC_InData_m5 + ADC_InData_m6)/4;
                
                //ADC_InData_p1 <= ADC_InData;
                //ADC_InData_p1 <= ADC_InData_m1 + ADC_InData_m2 + ADC_InData_m3 + ADC_InData_m4;
            end
            
            TriggerType_p1 <= TriggerType;
            TriggerThreshold_p1 <= TriggerThreshold;
        end
    end
    //DEBUG We need to give MCU control as to when to enter WaitForTriggerState
    always @(posedge clk)
    begin
    //Determines if trigger has happened
        //Inputs
            //Reset
            //RAMW_En
        //Outputs
            //triggered
            //TriggeredAddress 
        if (reset)
        begin
            Triggered <= 0;
            TriggeredAddress <= 0;
            TriggerWaitCounter <= 0;
        end
        else
        begin //Use on bit here to begin writing
            if ((RAMReadDone)) //If a change in trigger control regs
            begin 
                TriggeredAddress <= 0;
                Triggered <= 0;
                TriggerWaitCounter <= 0;

            end
            if (!Triggered)//If we are not in triggered state
            begin
                if (getNewData)
                begin
                    if (TriggerWaitCounter == 524287)
                    begin
                        if (TriggerType[1:0] == 0)
                        begin 
                            //Rising
                            if (ADC_InData > TriggerThreshold)
                            begin
                                if (ADCAvg1 < ADCAvg2)
                                begin
                                    Triggered <= 1;
                                    TriggeredAddress <= WriteAddress;
                                end
                            end                        
                        end
                        else if (TriggerType[1:0] == 1)
                        begin
                            //Falling
                            if ((ADC_InData > TriggerThreshold) || (ADC_InData_p1 > TriggerThreshold))
                            begin
                                if (ADCAvg1 > ADCAvg2)
                                begin
                                    Triggered <= 1;
                                    TriggeredAddress <= WriteAddress;
                                end
                            end
                        end
                        else if (TriggerType[1:0] == 2)
                        begin
                            //Threshold
                            if (TriggerType[2] == 0)
                            //above
                            begin
                                if (ADC_InData > TriggerThreshold)
                                begin
                                    Triggered <= 1;
                                    TriggeredAddress <= WriteAddress;
                                end
                            end
                            else
                            //below
                            begin
                                if (ADC_InData < TriggerThreshold)
                                begin
                                    Triggered <= 1;
                                    TriggeredAddress <= WriteAddress;
                               end
                            end
                            
                        end
                    end
                    else
                    begin
                        TriggerWaitCounter <= TriggerWaitCounter + 1;
                    end   
                end
            end
        end        
    end
endmodule
