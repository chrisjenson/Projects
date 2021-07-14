`timescale 1ns / 1ps

//`define REPO "LRU"; 
`define L  (8) //Num Bytes per line
`define K  (2) //2, 4, 8, 16 //Number lines per set
`define KN (256) //64, 256 //#Num Sets
`define Sets (128) //64, 256 //#Num Sets in cache
`define DataLength (57961) //Num datapoints Trace1
 //parameter DataLength = 59856; //Num datapoints Trace2\

module testbench();

    reg clk;
    
    //Generate Clock
    initial
    begin
        clk = 0;
        while(1)
        begin
            #5 clk = ~clk;
        end
    end
    /////////////////////////////////////////////
    //Reset
    reg reset; //Active Low
    initial
    //Initize reset
    begin
        reset = 1;
        #20 reset = 0;
    end
    //
    wire [23:0] Reference;
    wire [19:0] Tag;
    wire Index;
    wire NewInstructionFetch;
    //
    
    /////////////////////////////
    //Memory
    wire [63:0] ReadAddress;
    Memory u_Memory(
        .clk(clk),
        .reset(reset),
        .Reference(Reference),
        .ReadAddress(ReadAddress),
        .NewInstructionFetch(NewInstructionFetch)
    );
    ////////////////////////////////
    /////////////////////////////
    //Processor
    /*
    
    Processor u_Processor(
        
    );
    ////////////////////////////////
    */
    
    /////////////////////////////
    //Cache Control
    //Produces Hit/Miss
    wire WrEn;
    wire RdEn;
    wire Hit;
    
    CacheControl u_CacheControl(
        .clk(clk),
        .reset(reset),
        .Reference(Reference),
        .Tag(Tag),
        .Index(Index),
        .WrEn(WrEn),
        .RdEn(RdEn),
        .ReadAddress(ReadAddress),
        .NewInstructionFetch(NewInstructionFetch),
        .Hit(Hit)
    );
    ////////////////////////////////
    /////////////////////////////
    //CacheMem
    
//    wire [31:0] CacheReadOut;
//    wire [31:0] CacheWriteIn;
//    wire [31:0] CacheIndex;
    
    Cache u_Cache(
        .clk(clk),
        .Index(Index),
        .Tag(Tag),
        .Hit(Hit),
        .WrEn(WrEn),
        .RdEn(RdEn),
        .NewInstructionFetch(NewInstructionFetch)
    );
    
    ////////////////////////////////
    
endmodule
