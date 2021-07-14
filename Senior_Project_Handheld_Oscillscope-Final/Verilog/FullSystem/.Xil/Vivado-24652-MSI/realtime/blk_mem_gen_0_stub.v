// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "blk_mem_gen_v8_4_3,Vivado 2019.1" *)
module blk_mem_gen_0(clka, wea, addra, dina, clkb, addrb, doutb);
  input clka;
  input [1:0]wea;
  input [17:0]addra;
  input [15:0]dina;
  input clkb;
  input [17:0]addrb;
  output [15:0]doutb;
endmodule
