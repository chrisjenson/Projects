/** Chris Jenson
CSC345-02
Project 1 main.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

/*The maximum length command*/
#define MAX_LINE 80

/*Parsing what the user entered into seperate tokens*/
void readInCommand(char *args[], int *concur_flag, int *argv, int *should_run, int *cd_flag) {

    /*Initialize baseline variables*/
    char input_command[MAX_LINE];
    int len = 0;
    char delimiter[] = " ";

    /*Determine the length of command line arguements*/
    /*And place into input_command*/
    len = read(STDIN_FILENO, input_command, 80);

    /*Remove and replace newlines from the user command*/
    if (input_command[len - 1] == '\n') {
        /*Add ending to make it a string*/
        input_command[len - 1] = '\0';
    }

    /*Check for the previous command identifier*/
    if (strcmp(input_command, "!!") == 0) {
        /*Handle no previous commands*/
        if (*argv == 0) {
            printf("No commands in history.\n");
        }
        return;
    }

    /*Check if the user requested to exit*/
    else if ((strcmp(input_command, "exit") == 0) || (strcmp(input_command, "") == 0)) {
        *should_run = 0;    /*will end the while loop and terminate the program*/
    }

    else if ((strcmp(input_command, " ") == 0) || (strcmp(input_command, "") == 0)) {
        printf("Command Not Valid\n");
        *should_run = 0;    /*will end the while loop and terminate the program*/
    }

    *argv = 0;
    //*concur_flag = 0;

    /*Seperate the command into tokens*/
    /*Store the tokens in an array of character strings*/
    char *ptr = strtok(input_command, delimiter);

    while (ptr != NULL) {
        /*Check if the parent should wait for the child*/
        if (ptr[0] == '&') {
            *concur_flag = 1;
            ptr = strtok(NULL, delimiter);
            continue;
        }

        *argv += 1;
        args[*argv - 1] = strdup(ptr);
        ptr = strtok(NULL, delimiter);
        
        /*Needed to not mess up the args*/
        char holder[MAX_LINE / 2 + 1];
        strcpy(holder, args[*argv - 1]);    /*converts *char to char[]*/

        /*Block to handle changing directories*/
        int cd_error;   
        if(*cd_flag == 1){
            char *temp = strtok(args[*argv - 1], "\n"); /*Get the cd parameter*/
            /*printf("Old Directory: %s\n", getcwd(s, 100));  Uncomment if you want to see the old directory*/
            cd_error = chdir(temp); /*change the directory and store the success indicator*/

            if(cd_error != 0){  /*If it failed to cd*/
                printf("Directory Not Valid\n");
            }
        }

        /*Will cause the previous if to be true and receive the cd parameter in the case of a cd command*/
        if (strcmp(holder, "cd") == 0){
            *cd_flag = 1; 
        }
    }
    /*Set to NULL to indicate the completion of the command*/
    args[*argv] = NULL;

}

int main(void) {
    /*Command line arguments and baseline variables*/
    char *args[MAX_LINE / 2 + 1];
    char path[MAX_LINE];
    int should_run = 1; /*Flag for when to exit the program*/
    pid_t id;
    int concur_flag = 0; /*Flag for concurrency*/
    int argv = 0;
    int pipe_flag = 0; /*Flag for piping*/
    int cd_flag = 0; /*Flag for changing directory*/


    while (should_run) {
        /*Reset all flags after every command, some are redundant*/
        pipe_flag = 0;
        cd_flag = 0;
        concur_flag = 0;

        printf("%s: osh>", getcwd(path, 100));
        fflush(stdout);
        
        /*Read in the command from the command line*/
        readInCommand(args, &concur_flag, &argv, &should_run, &cd_flag);

        /*If there was a directory change, go to the next command*/
        if(cd_flag == 1){
            cd_flag = 0;
            continue;
        }

        /*Create the child process*/
        id = fork();

        /*If we are in the child process*/
        if (id == 0) {
            /*Move on if there are no arguements*/
            if (argv == 0) {
                continue;
            } 
            
            else {
                int redirect_flag = 0;
                int file;

                /*Check for "<", ">", or "|"*/
                for (int i = 1; i <= argv - 1; i++) {
                    /*Check for "<"*/
                    if (strcmp(args[i], "<") == 0) {
                        /*File name follows, and read its content*/
                        file = open(args[i + 1], O_RDONLY);
                        
                        /*Error handling: bad command*/
                        if ((file == -1) || (args[i + 1]  == NULL)) {
                            printf("Command Not Valid\n");
                            exit(1);
                        }

                        dup2(file, STDIN_FILENO);
                        args[i] = NULL;
                        args[i + 1] = NULL;
                        redirect_flag = 1;
                        break;
                    } 

                    /*Check for ">"*/
                    else if (strcmp(args[i], ">") == 0) {
                        /*File name follows, point ouput there*/
                        file = open(args[i + 1], O_WRONLY | O_CREAT, 0644);
                        
                        /*Error handling: bad command*/
                        if ((file == -1) || (args[i + 1]  == NULL)) {
                            printf("Command Not Valid\n");
                            exit(1);
                        }

                        dup2(file, STDOUT_FILENO);
                        args[i] = NULL;
                        args[i + 1] = NULL;
                        redirect_flag = 2;
                        break;
                    } 
                    
                    /*Check for "|"  */
                    else if (strcmp(args[i], "|") == 0) {
                        pipe_flag = 1;  /*Set the pipe flag*/
                        int fd1[2];

                        /*Error handling: bad pipe*/
                        if (pipe(fd1) == -1) {
                            fprintf(stderr, "Pipe Error\n");
                            return 1;
                        }

                        /*Split 2 commands for a pipe*/
                        char *first_command[i + 1];
                        char *second_command[argv - i - 1 + 1];
                        
                        /*Capture the first command*/
                        for (int j = 0; j < i; j++) {
                            first_command[j] = args[j];
                        }
                        first_command[i] = NULL;
                        
                        /*Capture the second command*/
                        for (int j = 0; j < argv - i - 1; j++) {
                            second_command[j] = args[j + i + 1];

                        }
                        second_command[argv - i - 1] = NULL;

                        /*Forking with a pipe*/
                        int id_pipe = fork();

                        /*Parent process*/
                        if (id_pipe > 0) {
                            wait(NULL);     /*Wait for child to execute*/
                            
                            /*Close the pipes*/
                            close(fd1[1]);  
                            dup2(fd1[0], STDIN_FILENO);
                            close(fd1[0]);
                            
                            /*Error handling: bad command*/
                            if (execvp(second_command[0], second_command) == -1) {
                                printf("Command Not Valid\n");
                                return 1;
                            }
                        } 
                        
                        /*Child Process*/
                        else if (id_pipe == 0) {

                            /*Close the pipes*/
                            close(fd1[0]);
                            dup2(fd1[1], STDOUT_FILENO);
                            close(fd1[1]);
                            
                            /*Error handling: bad command*/
                            if (execvp(first_command[0], first_command) == -1) {
                                printf("Command Not Valid\n");
                                return 1;
                            }
                            exit(1);
                        }
                        
                        /*Close the pipes*/
                        close(fd1[0]);
                        close(fd1[1]);
                        break;
                    }
                }

                /*Error handling: bad command*/
                if ((pipe_flag == 0) && (should_run == 1)) {
                    if (execvp(args[0], args) == -1) {
                        printf("Command Not Valid\n");
                        return 1;
                    }
                }

                /*Close the file*/
                if (redirect_flag == 1) {
                    close(STDIN_FILENO);
                } 
                
                else if (redirect_flag == 2) {
                    close(STDOUT_FILENO);
                }
                close(file);
            }
            exit(1);
        } 
        
        /*If parent and there is an &, wait for child*/
        else if (id > 0) {
            if (concur_flag == 0) 
                wait(NULL);
        } 
        
        /*Error Handling: bad fork*/
        else {
            printf("Fork Error");
        }
    }
}