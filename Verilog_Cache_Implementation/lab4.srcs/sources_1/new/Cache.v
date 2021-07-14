`timescale 1ns / 1ps

module Cache(
    input clk,
    input Index,
    input [19:0] Tag,
    input WrEn,
    input RdEn,
    input NewInstructionFetch,
    output reg Hit //1 = miss, 2 = hit
    );
    reg [6:0] WriteIndex1;
    reg [6:0] WriteIndex0;
    reg [6:0] LRUReplacementPriority1 [127:0];
    reg [6:0] LRUReplacementPriority0 [127:0];
    
    reg ValidBitsIndex1 [127:0]; //128 1 bits
    reg ValidBitsIndex0 [127:0]; //128 1 bits
    reg [19:0] TagBits1 [127:0]; //128 20 bits 
    reg [19:0] TagBits0 [127:0]; //128 20 bits
    integer i;
    
    initial 
    begin
        WriteIndex1 = 0;
        WriteIndex0 = 0;
        Hit = 0;
        for (i=0;i<128;i=i+1) begin
            ValidBitsIndex1[i] = 0; 
            ValidBitsIndex0[i] = 0; 
            TagBits1[i] = 0; 
            TagBits0[i] = 0; 
            LRUReplacementPriority1[i] = 0;
            LRUReplacementPriority0[i] = 0;
        end
    end
    
    wire WrEnPosedgePulse;
    wire WrEnNegedgePulse;
    reg WrEn_p1;
    always @(posedge clk)
    begin
        WrEn_p1 <= WrEn;
    end
    assign WrEnPosedgePulse = WrEn && ~WrEn_p1;
    assign WrEnNegedgePulse = ~WrEn && WrEn_p1;
    
    reg [6:0] HitIndex;   

    integer j;
    integer k;
    integer m;
    always @(*)
    begin
        ///////////////////////////////////////////////////////////////////////////////
        //Sets the write index as the lowest value in the replacement priority array
        WriteIndex1 = 0;
        WriteIndex0 = 0;
        for (j = 1; j < 128; j=j+1)
        begin
            if (LRUReplacementPriority1[j]< LRUReplacementPriority1[WriteIndex1])
            begin
                WriteIndex1 = j;
            end
            if (LRUReplacementPriority0[j]< LRUReplacementPriority0[WriteIndex0])
            begin
                WriteIndex0 = j;
            end
        end
    end

    always @(posedge clk)
    begin
        ///////////////////////////////////////////////////////////////////////////////
        //Decrement all values that are greater than the new index
        if (WrEnNegedgePulse)
        begin
            //if (j == 128)
            //begin
                for (m = 0; m < 128; m = m + 1)
                begin
                    if (Index == 1)
                    begin
                        if (LRUReplacementPriority1[m] > LRUReplacementPriority1[WriteIndex1])
                        begin
                            LRUReplacementPriority1[m] <= LRUReplacementPriority1[m] - 1;
                        end
                    end
                    else if (Index == 0)
                    begin
                        if (LRUReplacementPriority0[m] > LRUReplacementPriority0[WriteIndex0])
                        begin
                            LRUReplacementPriority0[m] <= LRUReplacementPriority0[m] - 1;
                        end
                    end
                end
                if (m == 128)
                begin
                    if (Index == 1)
                    begin
                        TagBits1[WriteIndex1] <= Tag;
                        ValidBitsIndex1[WriteIndex1] <= 1;
                        LRUReplacementPriority1[WriteIndex1] <= 127;
                    end
                    else if (Index == 0)
                    begin
                        TagBits0[WriteIndex0] <= Tag;
                        ValidBitsIndex0[WriteIndex0] <= 1;
                        LRUReplacementPriority0[WriteIndex0] <= 127;
                    end
                end
            //end
        end      
        if (Hit == 1)
        begin
            for (k = 0; k < 128; k=k+1)
            begin
                if (Index == 1)
                begin
                    if (LRUReplacementPriority1[k] > LRUReplacementPriority1[HitIndex])
                    begin
                        LRUReplacementPriority1[k] <= LRUReplacementPriority1[k] - 1;
                    end                
                end
                else if (Index == 0)    
                begin
                    if (LRUReplacementPriority0[k] > LRUReplacementPriority0[HitIndex])
                    begin
                        LRUReplacementPriority0[k] <= LRUReplacementPriority0[k] - 1;
                    end
                end                
            end
            if (k == 128)
            begin
                if (Index == 1)
                begin
                    LRUReplacementPriority1[HitIndex] <= 127;
                end
                else if (Index == 0)
                begin
                    LRUReplacementPriority0[HitIndex] <= 127;
                end                
            end
        end
    end

    reg [19:0] DebugTagBitsAtI;
    reg [19:0] DebugTagBitsAt0;

        
    always @(*)
    begin
    //Replace Tag and Set Valid
        if (RdEn)
        begin
            Hit = 0;
            if (Index == 1)
            begin
                for (i=0;i<128;i=i+1)
                begin
                    if (TagBits1[i] == Tag)
                    begin
                        HitIndex = i;
                        DebugTagBitsAtI = TagBits1[i];
                        Hit = 1;
                    end
                end
            end 
            else if (Index  == 0)
            begin
                for (i=0;i<128;i=i+1)
                begin
                    if (TagBits0[i] == Tag)
                    begin
                        HitIndex = i;
                        DebugTagBitsAt0 = TagBits0[i];
                        Hit = 1;
                    end
                end
            end       
        end 
        else if (NewInstructionFetch)
        begin
            Hit = 0;
            HitIndex = 0;
        end 
    end 
    
endmodule
