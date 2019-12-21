`timescale 1ns / 1ps

module Processor(
    input clk, rstn,
    input [7:0]PC,
    input [31:0]operation,

    output zFlag,
    output [3:0] ALUc,
    output [4:0]readReg1,
    output [4:0]readReg2,
    output [7:0] PCout,
    
    output reg [31:0] RD, //This is the Read data registed, not destination register
    output reg [31:0] A, //This is the output register
   
    output [63:0]readData1,
    output [63:0]readData2,
    output [63:0] Result,
    output [63:0] ALUB
    output [383:0]One_D_Array_IM,
    );
    
    reg [1:0] op;  
    reg [4:0] Rn;
    reg [4:0] Rd;
    reg [4:0] Rm;
    reg [5:0] Shamt;
    reg [8:0] DT_Address;
    reg [10:0]opcode;
    reg [25:0] BR_Address;
    reg [18:0] COND_BR_Address;
    reg [63:0] Extended;

    wire Reg2Loc, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, ALUOp1, ALUOp0, BranchMux, UncondBranch;
    
    wire [4:0] writeReg;
    wire [63:0] ReadDataStorage;
    wire [63:0] WriteDataReg;

    always @(*) begin //operation
        opcode = operation[31:21];
        
        COND_BR_Address = 0;
        //BR_Address = 0;       //dont need to have branch
        Rm = 0;
        Rn = 0;
        Rd = 0;
        op = 0;
        Shamt = 0;
        
        //Extended <= $signed(operation);
                
        case(opcode[10:3])
            //CBZ
            8'b10110100: begin
                
                COND_BR_Address = operation[23:5];
                Rd = operation[4:0];
                Extended <= $signed(COND_BR_Address);
            end
        endcase

//      case for branch
//        case(opcode[10:5])
//            //B
//            6'b000101: begin
//                BR_Address = operation[25:0];
//                Extended <= $signed(BR_Address);
//            end
//        endcase

        case (opcode)
            //LDUR
            11'b11111000010: begin
                DT_Address = operation[20:12];
                op = operation[11:10];
                Rn = operation[9:5];
                Rd = operation[4:0];
                Extended <= $signed(DT_Address);
            end
            
            //STUR
            11'b11111000000: begin
                DT_Address = operation[20:12];
                op = operation[11:10];
                Rd = operation[9:5];
                Rn = operation[4:0];
                Extended <= $signed(DT_Address);
            end
            
            //ADD
            11'b10001011000: begin
                Rm = operation[20:16];
                Shamt = operation[15:10];
                Rn = operation[9:5];
                Rd = operation[4:0];
            end
            
            //AND
            11'b10001010000: begin
                Rm = operation[20:16];
                Shamt = operation[15:10];
                Rn = operation[9:5];
                Rd = operation[4:0];
            end
            
            //SUB
            11'b11001011000: begin
                Rm = operation[20:16];
                Shamt = operation[15:10];
                Rn = operation[9:5];
                Rd = operation[4:0];
            end
            
            //ORR
            11'b10101010000: begin
                Rm = operation[20:16];
                Shamt = operation[15:10];
                Rn = operation[9:5];
                Rd = operation[4:0];
            end
        endcase     
    end
    
    Controller Controller(clk, rstn, opcode, Reg2Loc, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, ALUOp1, ALUOp0, UncondBranch, ALUc);
    Datapath Datapath(clk, rstn, Reg2Loc, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, ALUc, Rn, Rd, Rm, PC, readData1, readData2, Extended, ReadDataStorage, zFlag, Result, readReg1, readReg2, writeReg, PCout, WriteDataReg, ALUB);
    Register Register(clk, RegWrite, writeReg, readReg1, readReg2, WriteDataReg, readData1, readData2); //One_D_Array_DM_Output
    Storage Storage(clk, MemWrite, MemRead, Result, readData2, ReadDataStorage);
    
endmodule