`timescale 1ns / 1ps

module ADCInterface(
    input               clk, //from tb
    input               reset, //from tb
    input               ADC_SampleClock, //from timing gen
    input [9:0]         ADC_DataIn, //from DAB
    input [1:0]         ADC_BitSelect,
    output reg [15:0]   RAMW_Data
    );
    //DEBUG: ADD SATURATION
    //
    //May be better to force synthesis tools to utilize pads using following code:
    //https://www.xilinx.com/support/answers/6214.html
    //
    /////////////////////////////////////////////////
    //Get negedge and posedge pulses
    wire ADC_SampleClock_posedge_pulse;
    wire ADC_SampleClock_negedge_pulse;
    
    
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
    
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;
    assign ADC_SampleClock_negedge_pulse = ~ADC_SampleClock & ADC_SampleClock_p1;
    //End section
    //////////////////////////////////////////////////////////////    
    reg twoCounter;
    reg [15:0] ConcatRAMData;
    //DEBUG FIRST CONCATRAMDATA IS INVALID
    //DEBUG THIS SHOULD BE OUTPUTTING A FLAG WHEN READY, NOT RELYING ON SECONDPOSEDGEPULSE
    //DEBUG: Please verify this is doing Big Endian Format
    always @(*)
        //Select bits
        //This will affect trigger logic threshold
    begin
    end
 
    always @(posedge clk)
    //Select 8 bits from input data, concat with next 8 bit input, and set as output on negedge of sample clk
    //
    //Inputs
        //reset
        //ADC_SampleClock_negedge_pulse
        //ADC_DataIn
    //Outputs
        //Buffer_DataIn
    begin
        if (reset)
        begin
            twoCounter <= 0;
            RAMW_Data <= 0;
            ConcatRAMData[15:0] <= 0;
        end
        else
        begin
            if (ADC_SampleClock_posedge_pulse)
            begin
                if (twoCounter == 1)
                begin
                    ConcatRAMData[7:0] <= ADC_DataIn[9:2];  //DEBUG: MAKE THESE BITS SELECTABLE
                    twoCounter <= twoCounter + 1;
                    
                end
                else
                begin
                    RAMW_Data <= ConcatRAMData[15:0];
                    ConcatRAMData[15:8] <= ADC_DataIn[9:2];
                    twoCounter <= twoCounter + 1;
                end
            end
        end
    end
    
endmodule
