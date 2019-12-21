`timescale 1ns / 1ps
//In this file we will do the reading writing to registers

module Register(

    input clk, 
    input RegWrite,
    input [4:0] WriteReg,
    input [4:0] readReg1,
    input [4:0] readReg2,
    input [63:0] WriteDataReg
    
    output reg[63:0] readData1,
    output reg[63:0] readData2,
    );
    
    reg [63:0] RM[0:31];
    
    initial begin
        $readmemh("H:/363/project_5/RM.dat", RM);
    end
    reg [63:0] DMreg[0:31];
              
    always @(*) begin
        readData1 = RM[readReg1];
        readData2 = RM[readReg2];

        if (RegWrite == 1) begin
            RM[WriteReg] = WriteDataReg;
        end

    end
endmodule