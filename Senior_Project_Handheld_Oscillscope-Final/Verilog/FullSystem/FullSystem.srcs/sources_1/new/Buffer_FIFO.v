`timescale 1ns / 1ps

module Buffer_FIFO(
    input FIFO_OutRTR,
    
    input FIFO_InRTS,
    output FIFO_InRTR,
    
    input [15:0]FIFO_InData,
    output [15:0]FIFO_OutData,
        
    input clk,
    input reset,
    
    output DebugFIFOOutXFC,
    output DebugFIFOInXFC
    );
    
    wire FIFO_OutRTS;
    wire FIFO_InXFC;
    
    wire FIFO_OutXFC;
    
    assign DebugFIFOOutXFC = FIFO_OutXFC;
    assign DebugFIFOInXFC = FIFO_InXFC;
    //DEBUG: SHOULD ALSO BE RESET ON SLAVE SELECT
    reg [2:0] FIFO_NumInFIFO;//DEBUG: THIS NEEDS TO BE 3 BITS SINCE THERE ARE 4 POSITIONS
    reg [1:0] FIFO_WPTR;
    reg [1:0] FIFO_RPTR;
    
    assign FIFO_OutXFC = FIFO_OutRTR & FIFO_OutRTS;
    assign FIFO_InXFC = FIFO_InRTS & FIFO_InRTR;
    
    assign FIFO_OutRTS = (0 < FIFO_NumInFIFO) && (!reset);
    assign FIFO_InRTR = (FIFO_NumInFIFO < 4) && (!reset);
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            FIFO_WPTR <= 0;
            FIFO_RPTR <= 0;
            FIFO_NumInFIFO <= 0;
        end
        else
        begin
            if (FIFO_OutXFC) //Reading data
            begin
                FIFO_RPTR <= FIFO_RPTR + 1;
            end
            if (FIFO_InXFC) //Write data
            begin
                FIFO_WPTR <= FIFO_WPTR + 1;
            end
        end
        if (FIFO_InXFC != FIFO_OutXFC)
        begin
            if (FIFO_InXFC)
            begin
                FIFO_NumInFIFO <= FIFO_NumInFIFO + 1;
            end
            if (FIFO_OutXFC)
            begin
                FIFO_NumInFIFO <= FIFO_NumInFIFO - 1;
            end
        end
    end
    
    FIFO_RAM u_FIFO_RAM
    (
        .FIFO_WEN(FIFO_InXFC),     
        .FIFO_InWADR(FIFO_WPTR),  
        .FIFO_InWDAT(FIFO_InData),  
        .FIFO_OutRADR(FIFO_RPTR), 
        .FIFO_OutRDAT(FIFO_OutData),
                  
        .clk(clk)           
    );
    
    
endmodule
