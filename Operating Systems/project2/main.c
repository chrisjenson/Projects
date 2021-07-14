/** Chris Jenson & Brian Worts
CSC345-02
Project 2 main.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>

#include <sys/mman.h>
#include <sys/shm.h>

#define LINE_LENGTH 19  /*length of lines in in.txt +1 for newline*/
int flag = 0;   /*Global var that tracks if any the pthreads found a incorrect value*/

/*Structure for the board*/
typedef struct{
    int row;
    int column;
    int (* board)[9];   /*pointer to the board*/
} parameters;

/*Checks each if each row is a valid solution*/
void * check_rows(void * params){
    /*Load parameters from the struct*/
    parameters *data = (parameters*)params;
    int startingRow = data->row;
    int startingColumn = data->column;

    /*iterate through each value of a row*/
    for(int i = startingRow; i < 9; i++){
        int row[10] = {0};
        for(int j = startingColumn; j < 9; ++j){
            int value = data->board[i][j];
            /*Checking if the value has been used already to determine validity*/
            if(row[value]!= 0){
                flag = 1;
            }
            else
                row[value]= 1;
        }
    }
    return 0;
}

/*Check if a single row is a valid solution*/
void * check_row(void * params){
    /*Load parameters from the struct*/
    parameters *data = (parameters*)params;
    int checkRow = data->row;
    int startingColumn = data->column;

    /*iterate through each value of a row*/
    int row[10] = {0};
    for(int j = startingColumn; j < 9; ++j){
        int value = data->board[checkRow][j];
        /*Checking if the value has been used already to determine validity*/
        if(row[value]!= 0){
            flag = 1;
        }
        else
            row[value]= 1;
    }
    return 0;
}

/*Checks each if each column is a valid solution*/
void * check_columns(void * params){
    
    /*Load parameters from the struct*/
    parameters *data = (parameters*)params;
    int startingRow = data->row;
    int startingColumn = data->column;

    /*iterate through each value of a column*/
    for(int i = startingColumn; i < 9; i++){
        int column[10] = {0};
        for(int j = startingRow; j < 9; ++j){
            int value = data->board[i][j];
            /*Checking if the value has been used already to determine validity*/
            if(column[value]!= 0){
                flag = 1;
            }
            else
                column[value]= 1;
        }
    }
    return 0;    
}

/*Check if a single column is a valid solution*/
void * check_column(void * params){
    /*Load parameters from the struct*/
    parameters *data = (parameters*)params;
    int startingRow = data->row;
    int checkColumn = data->column;

    /*iterate through each value of a column*/
    int column[10] = {0};
    for(int j = startingRow; j < 9; ++j){
        int value = data->board[j][checkColumn];
        /*Checking if the value has been used already to determine validity*/
        if(column[value]!= 0){
            flag = 1;
        }
        else
            column[value]= 1;
    }
    return 0;    
}

/*Checks each if each sub 3x3 grid is a valid solution*/
void * check_subGrid(void * params){
    /*Load parameters from the struct*/
    parameters *data = (parameters*)params;
    int startingRow = data->row;
    int startingColumn = data->column;
    int stored[10] = {0};

    /*iterate through each value of a row*/
    for(int i = startingRow; i < startingRow + 3; i++){
        for(int j = startingColumn; j < startingColumn + 3; ++j){
            int value = data->board[i][j];
            /*Checking if the value has been used already to determine validity*/
            if(stored[value]!= 0){
                flag = 1;
            }
            else
                stored[value]= 1;
        }
    }
    return 0;    
}

/*Read in the board and pass to worker functions*/
int main(int argc, char** argv) {
    /*Initialize paramters*/
    int method_type = atoi(argv[1]);
    int board[9][9];
    char line[LINE_LENGTH] = {0};
    char delim[] = " ";
    clock_t begin = clock();
    char file_source[] = "input.txt";

    /*Open the file and error handle a bad path*/
    FILE *sudukoBoard = fopen(file_source, "r");
    if(sudukoBoard == NULL){
        printf("Failed to open file\n");
        return EXIT_FAILURE;
    }

    /*Read in the file contents*/
    int row_count = 0;
    int col_count = 0;
    while(fgets(line, LINE_LENGTH, sudukoBoard)){
        /*split on the space characters*/
        char *ptr = strtok(line, delim);

        /*Store a number in the 2d array then move to next */
        while(ptr != NULL){
            board[row_count][col_count] = atoi(ptr);
            ptr = strtok(NULL, delim);
            col_count += 1;
        }
        col_count = 0;
        row_count += 1;    
    }

    /* Output: print the 2d board array*/
    printf("BOARD STATE IN %s\n", file_source);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    /*Init shared memory*/
    const char* name = "COLLATZ";
    const int SIZE = 4096; /*Size of shared mem location*/

    int shm_fd; /*Shared mem file descriptor*/
    
    /*Pointer to shared mem location*/
    char *shmptr; 
    /*Open shared mem location*/
    shm_fd = shm_open(name, O_CREAT | O_RDWR,0666);
    /*Configure size of shared mem location*/
    ftruncate(shm_fd, SIZE);
    
    /*Map the shared mem location*/
    shmptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);


    /*1 thread, checks all 9 columns
        1 thread, checks all 9 rows
        9 threads, each check 1 subgrid*/
    if(method_type == 1){
        /*Setting the parameters for checking all the rows and all columns*/
        parameters *data0 = (parameters*)malloc(sizeof(parameters));
        data0-> row = 0;   /*passing the starting row*/
        data0-> column = 0;    /*passing the starting column*/
        data0-> board = board; /*passing the board*/
        
        /*Setting the parameters for checking each of the subgrids*/
        parameters *data1 = (parameters*)malloc(sizeof(parameters));
        data1-> row = 0;   /*passing the starting row*/
        data1-> column = 0;    /*passing the starting column*/
        data1-> board = board; /*passing the board*/

        parameters *data2 = (parameters*)malloc(sizeof(parameters));
        data2-> row = 0;   /*passing the starting row*/
        data2-> column = 3;    /*passing the starting column*/
        data2-> board = board; /*passing the board*/

        parameters *data3 = (parameters*)malloc(sizeof(parameters));
        data3-> row = 0;   /*passing the starting row*/
        data3-> column = 6;    /*passing the starting column*/
        data3-> board = board; /*passing the board*/        

        parameters *data4 = (parameters*)malloc(sizeof(parameters));
        data4-> row = 3;   /*passing the starting row*/
        data4-> column = 0;    /*passing the starting column*/
        data4-> board = board; /*passing the board*/

        parameters *data5 = (parameters*)malloc(sizeof(parameters));
        data5-> row = 3;   /*passing the starting row*/
        data5-> column = 3;    /*passing the starting column*/
        data5-> board = board; /*passing the board*/

        parameters *data6 = (parameters*)malloc(sizeof(parameters));
        data6-> row = 3;   /*passing the starting row*/
        data6-> column = 6;    /*passing the starting column*/
        data6-> board = board; /*passing the board*/

        parameters *data7 = (parameters*)malloc(sizeof(parameters));
        data7-> row = 6;   /*passing the starting row*/
        data7-> column = 0;    /*passing the starting column*/
        data7-> board = board; /*passing the board*/

        parameters *data8 = (parameters*)malloc(sizeof(parameters));
        data8-> row = 6;   /*passing the starting row*/
        data8-> column = 3;    /*passing the starting column*/
        data8-> board = board; /*passing the board*/

        parameters *data9 = (parameters*)malloc(sizeof(parameters));
        data9-> row = 6;   /*passing the starting row*/
        data9-> column = 6;    /*passing the starting column*/
        data9-> board = board; /*passing the board*/

        /*Create the required threads for this method*/
        pthread_t tid_allRows, tid_allColumns, tid1, tid2, tid3, tid4, tid5, tid6, tid7, tid8, tid9;

        /*Create all of the threads*/
        pthread_create(&tid_allRows, 0, check_rows, (void *)data0);
        pthread_create(&tid_allColumns, 0, check_columns, (void *)data0);
        pthread_create(&tid1, 0, check_subGrid, (void *)data1);
        pthread_create(&tid2, 0, check_subGrid, (void *)data2);
        pthread_create(&tid3, 0, check_subGrid, (void *)data3);
        pthread_create(&tid4, 0, check_subGrid, (void *)data4);
        pthread_create(&tid5, 0, check_subGrid, (void *)data5);
        pthread_create(&tid6, 0, check_subGrid, (void *)data6);
        pthread_create(&tid7, 0, check_subGrid, (void *)data7);
        pthread_create(&tid8, 0, check_subGrid, (void *)data8);
        pthread_create(&tid9, 0, check_subGrid, (void *)data9);

        /*Let all of the threads finsh using join*/
        pthread_join(tid_allRows, NULL);
        pthread_join(tid_allColumns, NULL);
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        pthread_join(tid3, NULL);
        pthread_join(tid4, NULL);
        pthread_join(tid5, NULL);
        pthread_join(tid6, NULL);
        pthread_join(tid7, NULL);
        pthread_join(tid8, NULL);
        pthread_join(tid9, NULL);

        /*Check the resutls of all the threads to see if we have a solution*/
        clock_t end = clock();
        if(flag) {
            printf("SOLUTION: %s (%f seconds)\n", "NO", (double)(end - begin)/CLOCKS_PER_SEC);
        }else{
            printf("SOLUTION: %s (%f seconds)\n", "YES", (double)(end - begin)/CLOCKS_PER_SEC);
        }
    }
    /*9 threads, each check 1 column
    9 threads, each check 1 row
    9 threads, each check 1 subgrid*/
    else if(method_type == 2){
        /*Setting the parameters for checking all rows, all columns, and subgrids*/
        parameters *data0 = (parameters*)malloc(sizeof(parameters));
        data0-> row = 0;   /*passing the starting row*/
        data0-> column = 0;    /*passing the starting column*/
        data0-> board = board; /*passing the board*/

        parameters *data1 = (parameters*)malloc(sizeof(parameters));
        data1-> row = 1;   /*passing the starting row*/
        data1-> column = 0;    /*passing the starting column*/
        data1-> board = board; /*passing the board*/

        parameters *data2 = (parameters*)malloc(sizeof(parameters));
        data2-> row = 2;   /*passing the starting row*/
        data2-> column = 0;    /*passing the starting column*/
        data2-> board = board; /*passing the board*/

        parameters *data3 = (parameters*)malloc(sizeof(parameters));
        data3-> row = 3;   /*passing the starting row*/
        data3-> column = 0;    /*passing the starting column*/
        data3-> board = board; /*passing the board*/        

        parameters *data4 = (parameters*)malloc(sizeof(parameters));
        data4-> row = 4;   /*passing the starting row*/
        data4-> column = 0;    /*passing the starting column*/
        data4-> board = board; /*passing the board*/

        parameters *data5 = (parameters*)malloc(sizeof(parameters));
        data5-> row = 5;   /*passing the starting row*/
        data5-> column = 0;    /*passing the starting column*/
        data5-> board = board; /*passing the board*/

        parameters *data6 = (parameters*)malloc(sizeof(parameters));
        data6-> row = 6;   /*passing the starting row*/
        data6-> column = 0;    /*passing the starting column*/
        data6-> board = board; /*passing the board*/

        parameters *data7 = (parameters*)malloc(sizeof(parameters));
        data7-> row = 7;   /*passing the starting row*/
        data7-> column = 0;    /*passing the starting column*/
        data7-> board = board; /*passing the board*/

        parameters *data8 = (parameters*)malloc(sizeof(parameters));
        data8-> row = 8;   /*passing the starting row*/
        data8-> column = 0;    /*passing the starting column*/
        data8-> board = board; /*passing the board*/

        parameters *data9 = (parameters*)malloc(sizeof(parameters));
        data9-> row = 0;   /*passing the starting row*/
        data9-> column = 0;    /*passing the starting column*/
        data9-> board = board; /*passing the board*/

        parameters *data10 = (parameters*)malloc(sizeof(parameters));
        data10-> row = 0;   /*passing the starting row*/
        data10-> column = 1;    /*passing the starting column*/
        data10-> board = board; /*passing the board*/

        parameters *data11 = (parameters*)malloc(sizeof(parameters));
        data11-> row = 0;   /*passing the starting row*/
        data11-> column = 2;    /*passing the starting column*/
        data11-> board = board; /*passing the board*/

        parameters *data12 = (parameters*)malloc(sizeof(parameters));
        data12-> row = 0;   /*passing the starting row*/
        data12-> column = 3;    /*passing the starting column*/
        data12-> board = board; /*passing the board*/        

        parameters *data13 = (parameters*)malloc(sizeof(parameters));
        data13-> row = 0;   /*passing the starting row*/
        data13-> column = 4;    /*passing the starting column*/
        data13-> board = board; /*passing the board*/

        parameters *data14 = (parameters*)malloc(sizeof(parameters));
        data14-> row = 0;   /*passing the starting row*/
        data14-> column = 5;    /*passing the starting column*/
        data14-> board = board; /*passing the board*/

        parameters *data15 = (parameters*)malloc(sizeof(parameters));
        data15-> row = 0;   /*passing the starting row*/
        data15-> column = 6;    /*passing the starting column*/
        data15-> board = board; /*passing the board*/

        parameters *data16 = (parameters*)malloc(sizeof(parameters));
        data16-> row = 0;   /*passing the starting row*/
        data16-> column = 7;    /*passing the starting column*/
        data16-> board = board; /*passing the board*/

        parameters *data17 = (parameters*)malloc(sizeof(parameters));
        data17-> row = 0;   /*passing the starting row*/
        data17-> column = 8;    /*passing the starting column*/
        data17-> board = board; /*passing the board*/

        parameters *data18 = (parameters*)malloc(sizeof(parameters));
        data18-> row = 0;   /*passing the starting row*/
        data18-> column = 0;    /*passing the starting column*/
        data18-> board = board; /*passing the board*/

        parameters *data19 = (parameters*)malloc(sizeof(parameters));
        data19-> row = 0;   /*passing the starting row*/
        data19-> column = 3;    /*passing the starting column*/
        data19-> board = board; /*passing the board*/

        parameters *data20 = (parameters*)malloc(sizeof(parameters));
        data20-> row = 0;   /*passing the starting row*/
        data20-> column = 6;    /*passing the starting column*/
        data20-> board = board; /*passing the board*/        

        parameters *data21 = (parameters*)malloc(sizeof(parameters));
        data21-> row = 3;   /*passing the starting row*/
        data21-> column = 0;    /*passing the starting column*/
        data21-> board = board; /*passing the board*/

        parameters *data22 = (parameters*)malloc(sizeof(parameters));
        data22-> row = 3;   /*passing the starting row*/
        data22-> column = 3;    /*passing the starting column*/
        data22-> board = board; /*passing the board*/

        parameters *data23 = (parameters*)malloc(sizeof(parameters));
        data23-> row = 3;   /*passing the starting row*/
        data23-> column = 6;    /*passing the starting column*/
        data23-> board = board; /*passing the board*/

        parameters *data24 = (parameters*)malloc(sizeof(parameters));
        data24-> row = 6;   /*passing the starting row*/
        data24-> column = 0;    /*passing the starting column*/
        data24-> board = board; /*passing the board*/

        parameters *data25 = (parameters*)malloc(sizeof(parameters));
        data25-> row = 6;   /*passing the starting row*/
        data25-> column = 3;    /*passing the starting column*/
        data25-> board = board; /*passing the board*/

        parameters *data26 = (parameters*)malloc(sizeof(parameters));
        data26-> row = 6;   /*passing the starting row*/
        data26-> column = 6;    /*passing the starting column*/
        data26-> board = board; /*passing the board*/

        /*Create the required threads for the row checks*/
        pthread_t tid0, tid1, tid2, tid3, tid4, tid5, tid6, tid7, tid8;
        /*Create the required threads for the column checks*/
        pthread_t tid9, tid10, tid11, tid12, tid13, tid14, tid15, tid16, tid17;
        /*Create the required threads for the subgrid checks*/
        pthread_t tid18, tid19, tid20, tid21, tid22, tid23, tid24, tid25, tid26;        

        /*Create all of the threads*/
        pthread_create(&tid0,  0, check_row, (void *)data0);
        pthread_create(&tid1,  0, check_row, (void *)data1);
        pthread_create(&tid2,  0, check_row, (void *)data2);
        pthread_create(&tid3,  0, check_row, (void *)data3);
        pthread_create(&tid4,  0, check_row, (void *)data4);
        pthread_create(&tid5,  0, check_row, (void *)data5);
        pthread_create(&tid6,  0, check_row, (void *)data6);
        pthread_create(&tid7,  0, check_row, (void *)data7);
        pthread_create(&tid8,  0, check_row, (void *)data8);
        pthread_create(&tid9,  0, check_column, (void *)data9);
        pthread_create(&tid10, 0, check_column, (void *)data10);
        pthread_create(&tid11, 0, check_column, (void *)data11);
        pthread_create(&tid12, 0, check_column, (void *)data12);
        pthread_create(&tid13, 0, check_column, (void *)data13);
        pthread_create(&tid14, 0, check_column, (void *)data14);
        pthread_create(&tid15, 0, check_column, (void *)data15);
        pthread_create(&tid16, 0, check_column, (void *)data16);
        pthread_create(&tid17, 0, check_column, (void *)data17);        
        pthread_create(&tid18, 0, check_subGrid, (void *)data18);
        pthread_create(&tid19, 0, check_subGrid, (void *)data19);
        pthread_create(&tid20, 0, check_subGrid, (void *)data20);
        pthread_create(&tid21, 0, check_subGrid, (void *)data21);
        pthread_create(&tid22, 0, check_subGrid, (void *)data22);
        pthread_create(&tid23, 0, check_subGrid, (void *)data23);
        pthread_create(&tid24, 0, check_subGrid, (void *)data24);
        pthread_create(&tid25, 0, check_subGrid, (void *)data25);
        pthread_create(&tid26, 0, check_subGrid, (void *)data26);

        /*Let all of the threads finsh using join*/
        pthread_join(tid0,  NULL);
        pthread_join(tid1,  NULL);
        pthread_join(tid2,  NULL);
        pthread_join(tid3,  NULL);
        pthread_join(tid4,  NULL);
        pthread_join(tid5,  NULL);
        pthread_join(tid6,  NULL);
        pthread_join(tid7,  NULL);
        pthread_join(tid8,  NULL);
        pthread_join(tid9,  NULL);
        pthread_join(tid10, NULL);
        pthread_join(tid11, NULL);
        pthread_join(tid12, NULL);
        pthread_join(tid13, NULL);
        pthread_join(tid14, NULL);
        pthread_join(tid15, NULL);
        pthread_join(tid16, NULL);
        pthread_join(tid17, NULL);
        pthread_join(tid18, NULL);
        pthread_join(tid19, NULL);
        pthread_join(tid20, NULL);
        pthread_join(tid21, NULL);
        pthread_join(tid22, NULL);
        pthread_join(tid23, NULL);
        pthread_join(tid24, NULL);
        pthread_join(tid25, NULL);
        pthread_join(tid26, NULL);

        /*Check the resutls of all the threads to see if we have a solution*/
        clock_t end = clock();
        if(flag) {
            printf("SOLUTION: %s (%f seconds)\n", "NO", (double)(end - begin)/CLOCKS_PER_SEC);
        }else{
            printf("SOLUTION: %s (%f seconds)\n", "YES", (double)(end - begin)/CLOCKS_PER_SEC);
        }
    }
    
    /*create 11 child processes:
    1 to check each column
    1 to check each row
    9 to check each 3x3 sub-grid*/
    else if(method_type == 3){
        
        pid_t id;
        int i;
        int numProcesses = 11;
        *shmptr = 0;
        for (i = 0; i < numProcesses; i++)
        {
            /*Map shared mem location*/
            shmptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
            id = fork();
            if (id == 0){
                //Child
                switch (i){
                    case 0 : ;
                        parameters *data0 = (parameters*)malloc(sizeof(parameters));
                        data0-> row = 0;   /*passing the starting row*/
                        data0-> column = 0;    /*passing the starting column*/
                        data0-> board = board; /*passing the board*/
                        check_columns((void *) data0);
                        break;

                    case 1 : ;
                        parameters *data00 = (parameters*)malloc(sizeof(parameters));
                        data00-> row = 0;   /*passing the starting row*/
                        data00-> column = 0;    /*passing the starting column*/
                        data00-> board = board; /*passing the board*/
                        check_rows((void *) data00);
                        break;

                    case 2 : ;
                        /*Setting the parameters for checking each of the subgrids*/
                        parameters *data1 = (parameters*)malloc(sizeof(parameters));
                        data1-> row = 0;   /*passing the starting row*/
                        data1-> column = 0;    /*passing the starting column*/
                        data1-> board = board; /*passing the board*/
                        check_subGrid((void *) data1);
                        break;

                    case 3 : ;
                        parameters *data2 = (parameters*)malloc(sizeof(parameters));
                        data2-> row = 0;   /*passing the starting row*/
                        data2-> column = 3;    /*passing the starting column*/
                        data2-> board = board; /*passing the board*/
                        check_subGrid((void *) data2);
                        break;

                    case 4 : ;
                        parameters *data3 = (parameters*)malloc(sizeof(parameters));
                        data3-> row = 0;   /*passing the starting row*/
                        data3-> column = 6;    /*passing the starting column*/
                        data3-> board = board; /*passing the board*/        
                        check_subGrid((void *) data3);
                        break;

                    case 5 : ;
                        parameters *data4 = (parameters*)malloc(sizeof(parameters));
                        data4-> row = 3;   /*passing the starting row*/
                        data4-> column = 0;    /*passing the starting column*/
                        data4-> board = board; /*passing the board*/
                        check_subGrid((void *) data4);
                        break;

                    case 6 : ;
                        parameters *data5 = (parameters*)malloc(sizeof(parameters));
                        data5-> row = 3;   /*passing the starting row*/
                        data5-> column = 3;    /*passing the starting column*/
                        data5-> board = board; /*passing the board*/
                        check_subGrid((void *) data5);
                        break;

                    case 7 : ;
                        parameters *data6 = (parameters*)malloc(sizeof(parameters));
                        data6-> row = 3;   /*passing the starting row*/
                        data6-> column = 6;    /*passing the starting column*/
                        data6-> board = board; /*passing the board*/
                        check_subGrid((void *) data6);
                        break;

                    case 8 : ;
                        parameters *data7 = (parameters*)malloc(sizeof(parameters));
                        data7-> row = 6;   /*passing the starting row*/
                        data7-> column = 0;    /*passing the starting column*/
                        data7-> board = board; /*passing the board*/
                        check_subGrid((void *) data7);
                        break;

                    case 9 : ;
                        parameters *data8 = (parameters*)malloc(sizeof(parameters));
                        data8-> row = 6;   /*passing the starting row*/
                        data8-> column = 3;    /*passing the starting column*/
                        data8-> board = board; /*passing the board*/
                        check_subGrid((void *) data8);
                        break;

                    case 10 : ;
                        parameters *data9 = (parameters*)malloc(sizeof(parameters));
                        data9-> row = 6;   /*passing the starting row*/
                        data9-> column = 6;    /*passing the starting column*/
                        data9-> board = board; /*passing the board*/
                        check_subGrid((void *) data9);
                        break;
                }
                if (flag == 1){
                    /*If flag, set value at shared location = 1*/
                    *shmptr = 1;
                }
                exit(0);
            }
            else if (id > 0){
                //Parent
                wait(NULL);
                /*Map shared mem location*/
                shmptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
                /*Get int value from shared mem location*/
                int finalFlag = *shmptr;
                /*After the last process*/
                if (i == 10){
                    clock_t end = clock();
                    if(finalFlag) {
                        printf("SOLUTION: %s (%f seconds)\n", "NO", (double)(end - begin)/CLOCKS_PER_SEC);
                    }
                    else{
                        printf("SOLUTION: %s (%f seconds)\n", "YES", (double)(end - begin)/CLOCKS_PER_SEC);
                    }
                    shm_unlink(name);
                }
            }
            else{
                printf("ERROR CREATING CHILD\n");
            }
        }
        
    }
    else{
        /*User requested a method not supported*/
        printf("Invalid Method Indicator\n");
        return 1;
    }

    /*Close the file*/
    if(fclose(sudukoBoard)){
        return EXIT_FAILURE;
    }

    return 0;
}