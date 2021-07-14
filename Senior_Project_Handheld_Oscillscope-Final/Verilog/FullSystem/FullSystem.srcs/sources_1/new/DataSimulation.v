`timescale 1ns / 1ps

module DataSimulation(
    input clk,
    input ADC_SampleClock,
    input SimDataHigh,
    input reset,
    output reg [9:0] SimData
    );
   
    wire ADC_SampleClock_posedge_pulse;
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
    
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;   
   
    reg [31:0] counter;
    always @(posedge clk)
    begin
        if (reset)
        begin
            SimData <= 0;
            counter <= 0;
        end
        else
        begin
            if (ADC_SampleClock_posedge_pulse)
            begin
                //COMMENT FOR SIM
                //SWITCH
                if (SimDataHigh)
                begin
                    SimData <= 64;
                end
                else
                begin
                    SimData <= 0;
                end
                
                //SQUARE WAVE
                /*counter <= counter + 1;
                if (counter < 25)
                begin
                    SimData <= 0;
                end
                else if ((counter >= 25)&&(counter <= 75))
                begin
                    SimData <= 150;
                end
                else
                begin
                    SimData <= 150;
                    counter <= 0;
                end*/
                
                //RAMP
                /*
                counter <= counter + 1;
                SimData <= counter;
                if (counter == 255)
                begin
                    SimData <= 0;
                    counter <= 0;
                end*/
                
            end
        end
    end
    
endmodule
