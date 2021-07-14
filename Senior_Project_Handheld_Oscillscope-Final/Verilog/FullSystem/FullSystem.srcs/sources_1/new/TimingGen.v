`timescale 1ns / 1ps

module TimingGen(
    input clk, //from tb
    input reset, //from tb
    output reg ADC_SampleClock, //To ADCInterface, DAB.
    output ADC_SampleClock_posedge_pulse,
    output ADC_SampleClock_negedge_pulse
    );
    
    reg [6:0] twoCounter;
    
    always @(posedge clk)
    begin
    //Generates a 25MHz sample clock
    //Inputs
        //Reset (Active Low)
    //Outputs  
        //ADC_SampleClock
        
        if (reset)
        begin
            ADC_SampleClock <= 0;
            twoCounter <= 0;
        end
        else
        begin
            if (twoCounter == 2)
            begin
                ADC_SampleClock <= ~ADC_SampleClock;
                twoCounter <= 0;
            end
            else
            begin
                twoCounter <= twoCounter + 1;
            end
        end
    end
    
    //BEGIN SECTION
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
        
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;
    assign ADC_SampleClock_negedge_pulse = ~ADC_SampleClock & ADC_SampleClock_p1;
    //End section
    
    
    
    
    

endmodule
