`timescale 1ns / 1ps

module FIFO_RAM(
    input       FIFO_WEN,
    input [1:0] FIFO_InWADR,
    input [15:0] FIFO_InWDAT,
    input [1:0] FIFO_OutRADR,
    output [15:0] FIFO_OutRDAT,
    
    input       clk
    );
    
    reg [15:0] dataBuffer[3:0];
    
    assign FIFO_OutRDAT = dataBuffer[FIFO_OutRADR];
    
    always @(posedge clk)
    begin
        if (FIFO_WEN)
        begin
            dataBuffer[FIFO_InWADR] <= FIFO_InWDAT;
        end
    end
    
endmodule
