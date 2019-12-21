`timescale 1ns / 1ps

module Controller(

    input clk, rstn
    input [10:0]opcode,
    
    output reg Reg2Loc, ALUSrc, MemtoReg, RegWrite, MemRead, MemWrite, Branch, ALUOp1, ALUOp0,UncondBranch,
    output reg[3:0] ALUc
    );

    always @(*) begin //As soon as it gets input, runs operation
    
        if (rstn == 0) begin
            Reg2Loc = 0;
            ALUSrc = 0;
            MemtoReg = 0;
            RegWrite = 0;
            MemRead = 0;
            MemWrite = 0;
            Branch = 0;
            ALUOp1 = 0;
            ALUOp0 = 0;
            //ALUc = 4'b0000;
        end
    
        case(opcode[10:3])
            //CBZ
            8'b10110100: begin
                Reg2Loc = 1;
                ALUSrc = 0;
                RegWrite = 0;
                MemRead = 0;
                MemWrite = 0;
                Branch = 1;
                ALUOp1 = 0;
                ALUOp0 = 1; 
                ALUc = 4'b0111;
                //MemtoReg = don't care                   
            end
        endcase

        //case for branch
//        case(opcode[11:6])    //dont need to have branch
//              //B
//              6'b000101: begin
//                ALUSrc = 0;
//                MemtoReg = 0;
//                RegWrite = 0;
//                MemRead = 0;
//                MemWrite = 0;
//                Branch = 0;
//                ALUOp1 = 0;
//                ALUOp0 = 0; 
//                ALUc = 4'b0000;
//                UncondBranch = 1;
//              end
//          endcase

        case (opcode)
            //LDUR
            11'b11111000010: begin       
                ALUSrc = 1;
                MemtoReg = 1;
                RegWrite = 1;
                MemRead = 1;
                MemWrite = 0;
                Branch = 0;
                ALUOp1 = 0;
                ALUOp0 = 0; 
                ALUc = 4'b0010;
                //Reg2Loc = don't care
            end
            
            //STUR
            11'b11111000000: begin
                Reg2Loc = 1;
                ALUSrc = 1;
                RegWrite = 0;
                MemRead = 0;
                MemWrite = 1;
                Branch = 0;
                ALUOp1 = 0;
                ALUOp0 = 0; 
                ALUc = 4'b0010;

                //MemtoReg = don't care
            end
            
            //ADD
            11'b10001011000: begin   
                Reg2Loc = 0;
                ALUSrc = 0;
                MemtoReg = 0;
                RegWrite = 1;
                MemRead = 0;
                MemWrite = 0;
                Branch = 0;
                ALUOp1 = 1;
                ALUOp0 = 0; 
                ALUc = 4'b0010;
            end
            
            //AND
            11'b10001010000: begin                
                Reg2Loc = 0;
                ALUSrc = 0;
                MemtoReg = 0;
                RegWrite = 1;
                MemRead = 0;
                MemWrite = 0;
                Branch = 0;
                ALUOp1 = 1;
                ALUOp0 = 0;
                ALUc = 4'b0000;
            end
            
            //SUB
            11'b11001011000: begin
                Reg2Loc = 0;
                ALUSrc = 0;
                MemtoReg = 0;
                RegWrite = 1;
                MemRead = 0;
                MemWrite = 0;
                Branch = 0;
                ALUOp1 = 1;
                ALUOp0 = 0; 
                ALUc = 4'b0110;
            end
            
            //ORR
            11'b10101010000: begin               
                Reg2Loc = 0;
                ALUSrc = 0;
                MemtoReg = 0;
                RegWrite = 1;
                MemRead = 0;
                MemWrite = 0;
                Branch = 0;
                ALUOp1 = 1;
                ALUOp0 = 0;
            end
        endcase
    end
endmodule