`timescale 1ns / 1ps


module Regs(
    input clk,
    input reset,
    input [7:0] Write_Data,
    input WrEn,
    input RdEn,
    input [4:0] Regs_Addr,
    output reg [7:0] Read_Data,
    
    //RAMReadDone
    input RAMReadDone,
    
    //For debug
    input [7:0] DebugWriteRegister,
    output [7:0] DebugLEDRegister,
    
    //Triggers
    output [7:0] TriggerType,
    output [7:0] TriggerThreshold,
    input Triggered,
    input TriggerWriteDone,
    //ADC Decimation
    output [1:0] SampleDecimationFactor,
    //Turns off write engine and read engine
    output onBit,
    
   output [1:0] IRSHighLow,
   output [3:0] Offset,
   output [1:0] ShiftControlRegister,
   output DEBUGTriggeredReg
    
    );
    //INPUT need an input for the write only register with the on-bit
    //also a read only bit
    
    reg [7:0] registers [15:0];
    
    assign DebugLEDRegister = registers[7]; //4 //LEDs
    assign DEBUGTriggeredReg = registers[15][0];
    assign TriggerThreshold = registers[7];
    assign TriggerType = registers[6];
    assign onBit = registers[9][0]; //9
    always @(posedge clk)
    begin
        registers[5] <= DebugWriteRegister; //8'b11111111; //Scratch W reg- Switches
        if (reset)
        begin 
            registers[0] <= 8'b01000010; //B
            registers[1] <= 8'b01000011; //C
            registers[2] <= 8'b01010011; //S
            registers[3] <= 8'b01010101; //Version ID
            registers[4] <= 8'b01010101; //scratch R/W reg LEDs- Debug register

            registers[6] <= 8'b00000000; //Trigger and Trigger slope
            registers[7] <= 8'b00000000; //Trigger Threshold Value
            registers[8] <= 8'b00000000; //Sample Decimation
            registers[9] <= 8'b00000000; //on-bit
            registers[10] <= 8'b00000000; //reset
            registers[11] <= 8'b00000000; //IRS_High and Low
            registers[12] <= 8'b00000000; //Offset
            registers[13] <= 8'b00000000; //Shift Control Register
            registers[14] <= 8'b00000000; //Gain
            registers[15] <= 8'b00000000; //Triggered & TriggerWriteDone
            
        end
        else
        begin
            if (WrEn)
            begin 
                registers[Regs_Addr] <= Write_Data;
            end
            //if (Triggered == 1)
            //begin
            //    registers[15][0] <= 1'b1;
            //end
            if (TriggerWriteDone == 1)
            begin
                registers[15][0] <= 1'b1;
                registers[9] <= 8'b00000000; //On bit
            end
            else if (RAMReadDone)
            begin
                
               /* registers[6] <= 8'b00000000; //Trigger and Trigger slope
                registers[7] <= 8'b00000000; //Trigger Threshold Value
                */
                registers[15] <= 8'b00000000; //Triggered
            end
            
        end
    end
    /*always @(posedge clk)
    begin
        if (reset)
        begin 
            
        end
        else
        begin
            if (RAMReadDone)
            begin
                
            end
        end
    end*/
    always @(*)
    begin
        if (RdEn) //DEBUG: Shouldnt matter what read data value is when not reading
        begin
        //DEBUG CHANGE TO BLOCK WRITE ATTEMPTS TO READ ONLY REGS
        //case readonly regs
            //return error or default value
        //default
            //normal read
            Read_Data = registers[Regs_Addr];
        //DEBUG Pick switches and assign to bits in registers. Changing switches will show changes in MISO
        end
        else//Always give a value in a combinational block!!
        begin
            Read_Data = 8'b00000000;
        end
    end
    
endmodule
