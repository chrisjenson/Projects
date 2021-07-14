/** Chris Jenson & Brian Worts
CSC345-02
Project 3 main_pr.c */

/*=======================NEED TO ADD FIFO REPLACEMENT POLICY======================================*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PAGES 256       /*number of pages*/
#define PAGE_SIZE 256   /*page size*/
#define FRAMES 256      /*number of frames*/
#define FRAME_SIZE 256  /*frame size*/
#define TLB_SIZE 16     /*size of the TLB*/

/*Stucture for the TLB*/
typedef struct{
	int page_number;
	int frame_number;
} page_frame_node;

/*Input and output files*/
FILE *BACKING_STORE;    /*holds the BACKING_STORE.bin file*/
FILE *addrFile;         /*will hold the address file from command line*/
FILE *out1File;         /*will hold the logical address being translated*/
FILE *out2File;         /*will hold the corresponding physical address*/
FILE *out3File;         /*will hold the signed byte value in physical; mem at the translated addr*/

signed char phys_MEM[FRAMES][FRAME_SIZE];
int page_table[PAGES];
page_frame_node TLB[TLB_SIZE];

int main (int argc, char* argv[]){
    
    char addr[10];      /*will hold address read in from addresses.txt*/
    int logical_addr;   /*logical address*/
    signed char value;  //signed byte
	int addr_count = 0;
    int frame_count = 0;
    int fault_count = 0;
    int TLB_hits = 0;
    int TLB_count = 0;

    /*Output variables*/
	float pageFault_rate;
	float TLB_hit_rate;

    /*Check for the proper amount of arguements*/
	if (argc < 2){
		printf("Invalid Arguments\n");
		return -1;
	}

    /*open and verify the addresses.txt file specified by the user*/
	addrFile = fopen(argv[1], "r");
	BACKING_STORE = fopen("BACKING_STORE.bin", "rb");

    if (addrFile == NULL || BACKING_STORE == NULL){
		printf("Invalid File\n");
		return -1;
	}
    out1File = fopen("out1.txt", "w");
    out2File = fopen("out2.txt", "w");
    out3File = fopen("out3.txt", "w");

    /*Populate the tables and mem with inital values*/
    for(int i = 0; i < FRAMES; i++){        /*populate physical memory*/
        for(int j = 0; j < FRAME_SIZE; j++){
            phys_MEM[i][j] = 0;
        }
    }
    for(int i = 0; i < PAGES; i++){         /*populate the page table*/
        page_table[i] = -1;
    }
    for(int i = 0; i < TLB_SIZE; i++){      /*populate the TLB*/
        TLB[i].page_number = -1;
        TLB[i].frame_number = -1;
    }

    /*while there are still addresses to read*/
	while (fgets(addr, 10, addrFile) != 0){
		addr_count++;
        logical_addr = atoi(addr);
        int TLB_flag = 0;

        /*obtain page num and offset*/
        int page_Num = (logical_addr >> 8) & (255);
        int offset = logical_addr & (255);
        int frame_Num;

        /*Check the TLB for the page num*/
        for(int i = 0; i < TLB_SIZE; i++){
            if(TLB[i].page_number == page_Num){
                frame_Num = TLB[i].frame_number;
                TLB_flag = 1;
            }
        } if(TLB_flag == 0){
            frame_Num = -1;
        }

        /*if the page number is not in the TLB*/
        if(frame_Num == -1){

            /*check if page num is found in the page table*/
            frame_Num = page_table[page_Num];

            /*if the page num is not in the page table*/
            if(frame_Num == -1){
                /*give a frame number*/
                frame_Num = frame_count++ % FRAMES;
                /*add to the page table*/
                page_table[page_Num] = frame_Num;

                fault_count++;

                /*access backing store to get a page with error handling*/
                if (fseek(BACKING_STORE, page_Num * PAGE_SIZE, SEEK_SET) != 0){
                    printf("fseek error\n");
                    return -1;
                }                
                if (fread(phys_MEM[frame_Num], sizeof(signed char), FRAME_SIZE, BACKING_STORE) == 0){
                    printf("fread error\n");
                    return -1;
                }
            
            /*if the TLB missed, add to TLB*/
            TLB[TLB_count].page_number = page_Num;
            TLB[TLB_count].frame_number = frame_Num;
            TLB_count = (TLB_count + 1) % TLB_SIZE;
            }
        } 
        else {
            /*then the TLB had a hit*/
            TLB_hits++;
        }

        /*calculate the physical address and the value*/
        int phys_addr = (frame_Num << 8) | offset;
        value = phys_MEM[frame_Num][offset];

        /*print the results to the three output files specified by the assignment*/
        fprintf(out1File, "Virtual address: %d\n", logical_addr);
        fprintf(out2File, "Physical address: %d\n", phys_addr);	
        fprintf(out3File, "Value: %hi\n", value);
	}

    /*Output the results of the virtual memory manager*/
	pageFault_rate = (float)fault_count / (float)addr_count;
	TLB_hit_rate = (float)TLB_hits / (float)addr_count;
	printf("Page faults = %d/%d, %.3f\n", fault_count, addr_count, pageFault_rate);
	printf("TLB hits = %d/%d, %.3f\n", TLB_hits, addr_count, TLB_hit_rate);

    /*Close the files used*/
    fclose(addrFile);
    fclose(out1File);
    fclose(out2File);
    fclose(out3File);

    return 0;
}