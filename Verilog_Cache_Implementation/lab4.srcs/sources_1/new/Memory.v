`timescale 1ns / 1ps

module Memory( //BITS
    input clk,
    input reset,
    input [63:0] ReadAddress,
    input NewInstructionFetch,
    output reg [23:0] Reference
    );
    
    reg [23:0] Memory [59999:0];//57962
    reg [23:0] Input;
    integer i;
    integer File;
    initial 
    begin
        i = 0;
        //Initialize Memory File 
        File = $fopen("D:/CELab2/Lab4/TRACE1.DAT", "rb");
        while (!$feof(File))
        begin
            Input = ($fgetc(File)) | ($fgetc(File) << 8) | ($fgetc(File) << 16);
            Memory[i] = Input;
            i=i+1;
        end
        $fclose(File);
    end

    always @(*)
    begin
        if (reset)
        begin
            
        end
        else
        begin
            Reference <= Memory[ReadAddress];
        end
    end
    
    

endmodule
