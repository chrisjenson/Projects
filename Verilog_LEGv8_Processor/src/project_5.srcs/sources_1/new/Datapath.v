`timescale 1ns / 1ps

module Datapath(
    
    input clk, rstn, 
    input Reg2Loc, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch,
    input [3:0] ALUc,
    input [4:0] Rn,Rd,Rm,
    input [7:0] PC,
    input [63:0] readData1, readData2,
    input [63:0] Extended,
    input [63:0] ReadDataStorage,

    output zFlag,
    output [63:0] result,
    
    output reg [4:0] readReg1, readReg2, writeReg,
    output reg[7:0] PCout,
    output reg[63:0] WriteDataReg,
    output reg [63:0] ALUB
    );
    
    reg BranchMux;
    
    ALU ALU(clk, readData1, ALUB, ALUc, result, zFlag);
    
    always @(*) begin //posedgeclk

        readReg1 = Rn; 
        writeReg = Rd;

       case(Reg2Loc)
            0: begin
                readReg2 = Rm;
            end
            1: begin
                readReg2 = Rd;
            end
        endcase

        case(ALUSrc)
            0: begin
                ALUB = readData2;
            end
            1: begin
                ALUB = Extended;
            end
        endcase

        case(MemtoReg)
            0: begin
                WriteDataReg = result;
            end
            1: begin
                WriteDataReg = ReadDataStorage;
            end
        endcase
        
        if (BranchMux == 1) begin //BranchMux == 1
           PCout = (Extended) + PC; //DEBUG: go back to where the branch was called and Extended * 4
        end

        if (MemWrite == 1) begin //STUR
            //mem[result] = readData2
        end
        if (MemRead == 1) begin //LDUR
            //ReadDataStorage = Storage[result]
        end
        
        if ((Branch == 1) && (zFlag == 1)) begin
            BranchMux = 1;
        end
        else begin
            BranchMux = 0;
        end
        
        
    end
endmodule