`timescale 1ns / 1ps

module CacheControl
    (
    input clk,
    input reset,
    input [23:0] Reference,
    input  Hit,
    output [19:0] Tag,
    output reg [63:0] ReadAddress,
    output Index,
    output reg WrEn,
    output reg RdEn,
    output reg NewInstructionFetch
    );
    
    reg [63:0] HitCount;
    reg [63:0] MissCount;
    reg [63:0] RefCount;
    
    wire [2:0] Offset;
    
    assign Tag = Reference[23:4]; 
    assign Index = Reference[3]; 
    assign Offset = Reference[2:0]; 
    
    always @(posedge clk)
    begin
    //Drive ReadAddress
    //Output:
        //ReadAddress
        if (reset)
        begin
            ReadAddress <= -1;
        end
        else
        begin
            if (NewInstructionFetch)
            begin
                ReadAddress <= ReadAddress + 1;
            end
        end
    end
    
    always @(posedge clk)
    begin
    //Output: 
        //NewInstructionFetch
        if (reset)
        begin
            NewInstructionFetch <= 1;
            RdEn <= 0;
            WrEn <= 0;
            HitCount <= 0;
            MissCount <= 0;
            RefCount <= 0;
        end
        else
        begin
            if (NewInstructionFetch) 
            begin
                RefCount <= RefCount + 1;
                NewInstructionFetch <= 0;
                RdEn <= 1;
            end
            else if (RdEn)
            begin
                if (Hit == 0)
                begin //MISS
                    WrEn <= 1;
                    MissCount <= MissCount + 1;
                    RdEn <= 0;
                end
                else if (Hit  == 1)
                begin //HIT
                    HitCount <= HitCount + 1;
                    NewInstructionFetch <= 1;
                    RdEn <= 0;
                end
            end
            else if (WrEn)
            begin
                WrEn <= 0;
                NewInstructionFetch <= 1;
            end
            
        end
    end
    
    
endmodule
