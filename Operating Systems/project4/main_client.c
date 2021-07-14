#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 
#include <pthread.h>
#include <ctype.h>

#define PORT_NUM 4069

int new_room_flag = 0;
int print_room_flag = 0;
int join_room_flag = -1;

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

typedef struct _ThreadArgs {
	int clisockfd;
} ThreadArgs;

void* thread_main_recv(void* args)
{
	pthread_detach(pthread_self());

	int sockfd = ((ThreadArgs*) args)->clisockfd;
	free(args);

	//printf("DEBUG client socket: %i\n", sockfd);

	// keep receiving and displaying message from server
	char buffer[512];
	int n;

	n = recv(sockfd, buffer, 512, 0);
	//printf("DEBUG first rec: %s\n", buffer);

	printf("\n%s\n", buffer);
	memset(buffer, 0, 512);
		

	while (n > 0) {
		n = recv(sockfd, buffer, 512, 0);
		//("DEBUG second rec: %s\n", buffer);

		if (n < 0) error("ERROR recv() failed");
		printf("\n%s\n", buffer);
		memset(buffer, 0, 512);
	}
	memset(buffer, 0, 512);

	return NULL;
}

void* thread_main_send(void* args)
{
	pthread_detach(pthread_self());

	int sockfd = ((ThreadArgs*) args)->clisockfd;
	free(args);
	int n;


	//==========PRINT ROOM command===========//
	//tell the server to make a new room
	char print_buffer[256];
	if(print_room_flag == 1){
		sprintf(print_buffer, "room:%s", "print");
		
		n = send(sockfd, print_buffer, strlen(print_buffer), 0);
		if (n < 0) error("ERROR writing to socket");

		print_room_flag = 0;
	}
	memset(print_buffer, 0, 256);


	usleep(100000);


	//========ASK FOR AND RECEIVE NICKNAME=======//
	char name_buffer[256];
	char nickname[64];
	int yes = 1;
	printf("\033[0;37mEnter a nickname (blank for none):\n");
	fgets(nickname, 63, stdin);

	if(strlen(nickname) == 1){
		sprintf(nickname, "NN:%s", "127.0.0.1");
	} else {
		int index = strlen(nickname)-1;
		nickname[index] = 0;
		sprintf(name_buffer, "NN:%s", nickname);
	}
	
	n = send(sockfd, name_buffer, strlen(name_buffer), 0);
	if (n < 0) error("ERROR writing to socket");

	//printf("\nHello %s, press enter to join\n", nickname);
	//fgets(nickname, 63, stdin);
	memset(name_buffer, 0, 256);
	memset(nickname, 0, 64);

	usleep(100000);



	//==========NEW ROOM command===========//
	//tell the server to make a new room
	char room_buffer[256];
	if(new_room_flag == 1){
		sprintf(room_buffer, "room:%s", "new");
		
		n = send(sockfd, room_buffer, strlen(room_buffer), 0);
		if (n < 0) error("ERROR writing to socket");

		new_room_flag = 0;
	}
	memset(room_buffer, 0, 256);

	usleep(100000);


	//==========JOIN ROOM command===========//
	//tell the server to make a new room
	char join_buffer[256];
	if(join_room_flag != -1){
		sprintf(join_buffer, "join:%i", join_room_flag);
		
		n = send(sockfd, join_buffer, strlen(join_buffer), 0);
		if (n < 0) error("ERROR writing to socket");

		join_room_flag = -1;
	}
	memset(join_buffer, 0, 256);

	usleep(100000);



	// keep sending messages to the server
	char mess_buffer[256];
	//char buffer[256];

	//==========SEND MESSAGES===========//
	while (1) {
		// You will need a bit of control on your terminal
		// console or GUI to have a nice input window.
		printf("\n\033[0;37mPlease enter the message: ");
		fgets(mess_buffer, 255, stdin);

		if (strlen(mess_buffer) == 1) mess_buffer[0] = '\0';

		n = send(sockfd, mess_buffer, strlen(mess_buffer), 0);
		if (n < 0) error("ERROR writing to socket");

		memset(mess_buffer, 0, 256);

		if (n == 0) break; // we stop transmission when user type empty string
	}
	memset(mess_buffer, 0, 256);

	return NULL;
}

int main(int argc, char *argv[])
{
	if (argc < 2) error("Please speicify hostname");

	else if (argc == 2){	//no parameters passed
		print_room_flag = 1;
	}

	else if (argc == 3){
		//argv = room num or new
		if(strcmp(argv[2], "new") == 0){
			//printf("ENTERED new\n");
			new_room_flag = 1;

		} else if(atoi(argv[2]) < 5 && atoi(argv[2]) > -1){
			//printf("ENTERED digit\n");
			join_room_flag = atoi(argv[2]);

		} else{
			error("Invalid third parameter");
		}
	} else{
		error("Too many arguments");
	}

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) error("ERROR opening socket");

	struct sockaddr_in serv_addr;
	socklen_t slen = sizeof(serv_addr);
	memset((char*) &serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(PORT_NUM);

	printf("\033[0;37mConnecting to %s...\n", inet_ntoa(serv_addr.sin_addr));

	int status = connect(sockfd, 
			(struct sockaddr *) &serv_addr, slen);
	if (status < 0) error("ERROR connecting");

	pthread_t tid1;
	pthread_t tid2;

	ThreadArgs* args;
	
	//send messages to server
	//========SEND NICKNAME TO SERVER=======//
	args = (ThreadArgs*) malloc(sizeof(ThreadArgs));
	args->clisockfd = sockfd;
	pthread_create(&tid1, NULL, thread_main_send, (void*) args);

	//receive messages from the server
	args = (ThreadArgs*) malloc(sizeof(ThreadArgs));
	args->clisockfd = sockfd;
	pthread_create(&tid2, NULL, thread_main_recv, (void*) args);

	// parent will wait for sender to finish (= user stop sending message and disconnect from server)
	pthread_join(tid1, NULL);

	close(sockfd);

	return 0;
}

