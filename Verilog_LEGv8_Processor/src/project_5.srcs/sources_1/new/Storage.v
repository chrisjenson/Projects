`timescale 1ns / 1ps

module Storage(
        
        input clk,
        input MemWrite,MemRead,
        input [63:0]Result,
        input [63:0] WriteDataStorage, //readData2
        
        output reg [63:0] ReadDataStorage
    );
    
    
     reg [63:0] DM[0:31];
       
     initial begin
         $readmemh("H:/363/project_5/DM.dat", DM);
     end
     
     always @(*) begin
         if (MemRead == 1) begin
            ReadDataStorage = DM[Result];
         end
        
        if (MemWrite == 1) begin
            DM[Result] = WriteDataStorage;
        end
     end
endmodule