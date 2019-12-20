`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:53:45 10/03/2013 
// Design Name: 
// Module Name:    alu 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module alu2(a,b,ALUc,z,cout,cin);
    input [15:0] a;
    input [15:0] b;
    input [2:0] ALUc;
	 input cin;
	 output [15:0] z; 
	 output cout;
    
	reg c;
	reg [16:0] y; 		  //17 bits for carry (c)
	

always@(ALUc or b)
begin
	case(ALUc)			
	0 : begin y = ~a; c = cin; end 					// NOT
	1 : begin y = a + b + cin; c = y[16]; end		// ADC
	3 : begin y = y + 1; c = y[16]; end		 		// INCREMENT ACC
	4 : begin y = 0; c = cin; end						// Store & Clear							
	5 : begin y = b; c = cin; end						// Pass b
	endcase
end

	assign z = y;
	assign cout = c;
	
endmodule
