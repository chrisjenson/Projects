#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT_NUM 4069

char serverIP[64];

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

typedef struct _USR {
	int room_num; //users room number
	char nickname[64]; // users nickname
	int color;		// the users specific color
	int clisockfd;		// socket file descriptor
	struct _USR* next;	// for linked list queue
} USR;

USR *head = NULL;
USR *tail = NULL;

void print_connections(){
	printf("Updated Connections:\n");
	char buffer[512];

	// traverse through all connected clients
	USR* cur = head;
	while (cur != NULL) {
		// Print address
		printf("%s\n",cur->nickname);
		cur = cur->next;
	}	
}

					//     			 red			green		yellow			blue		purple			cyan	
	char color_options[6][10] = { "\033[0;31m", "\033[0;32m", "\033[0;33m", "\033[0;34m", "\033[0;35m", "\033[0;36m"};
	int color_in_use[6] = {0, 0, 0, 0, 0, 0};

	int room_in_use[5] = {0, 0, 0, 0, 0};

void add_tail(int newclisockfd)
{
	int index = -1;
	//get first instance of 0 for colors
	for(int i = 0; i < 6; i++){
		if(color_in_use[i] == 0){
			index = i;
			break;
		}
	} if (index == -1)	{
		printf("ERROR: Too many connections"); 
	}

	if (head == NULL) {
		head = (USR*) malloc(sizeof(USR));
		
		head->color = index;
		color_in_use[index] = 1;
		
		head->clisockfd = newclisockfd;
		head->next = NULL;
		tail = head;
	} else {
		tail->next = (USR*) malloc(sizeof(USR));
		
		tail->color = index;
		color_in_use[index] = 1;
		
		tail->next->clisockfd = newclisockfd;
		tail->next->next = NULL;
		tail = tail->next;
	}
}

void remove_node(struct _USR** head_ref, int newclisockfd){

	struct _USR *temp = *head_ref, *prev;

	//check if head is where the delete is
	if(temp != NULL && temp->clisockfd == newclisockfd){
		color_in_use[temp->color] = 0;
		*head_ref = temp->next; //update the head
		free(temp); //free the mem
		return;
	} 
	else {
		//find the key
		while(temp != NULL && temp->clisockfd !=  newclisockfd){
			color_in_use[temp->color] = 0;
			prev = temp;
			temp = temp->next;
		}
	}
	//unlink the node
	prev->next = temp->next;

	free(temp); //free the mem
}

void broadcast(int fromfd, char* message)
{
	//printf("DEBUG top of broadcast: %s\n", message);



	// figure out sender address
	struct sockaddr_in cliaddr;
	socklen_t clen = sizeof(cliaddr);
	if (getpeername(fromfd, (struct sockaddr*)&cliaddr, &clen) < 0) error("ERROR Unknown sender!");
	char buffer[512];
	char sender[256];
	char room_list[512];

	char temp[256];
	sprintf(temp, "%s", message);	//make a copy that we can tokenize
	char *token = strtok(temp, ":");//tokenize the copy of message (temp)

	//printf("DEBUG after token: %s\n", message);
	//printf("DEBUG token: %s\n", token);



	//setting the nickname
	if(strcmp(token, "NN") == 0){	
		token = strtok(NULL, ":");	//get the nickname
		
		USR* cur = head;
		while (cur != NULL) {		//find the requesting user
			if (cur->clisockfd == fromfd) {
				sprintf(cur->nickname, "%s", token);	//store their nickname
			}
			cur = cur->next;
		}
		print_connections();		//print the updated connections
	}	 
	
	

	//chat room applications
	else if (strcmp(token, "room") == 0){	
		token = strtok(NULL, ":");	//tokenize the message

		USR* cur = head;	//set the head

		//create a new room
		if(strcmp(token, "new") == 0){
			int index = -1;
			int i;
			char temp2[256];

			for(i = 0; i < 5; i++){		//get first instance of 0
				if(room_in_use[i] == 0){
					index = i;
					break;
				}
			} if (i == 5)	{	///error handle
				printf("ERROR: No more rooms"); 
			}
			room_in_use[index] = 1;
			
			//assign the user to the new room
			cur = head;
			while (cur != NULL) {
				if (cur->clisockfd == fromfd) {
					cur->room_num = index;	//store nickname
				}
				cur = cur->next;
			}

			sprintf(temp2, "Connected to %s with new room number %i\n", serverIP, index);

			int nmsg = strlen(temp2);
			int nsen = send(fromfd, temp2, nmsg, 0);

			memset(temp2, 0, 256); //always clear buffer


		//print the list of rooms
		} else if (strcmp(token, "print") == 0){
			char temp[64];
			int room_ocu = 0;

			sprintf(temp, "\n\033[0;37mServer says following options are available:\n");
			strcat(room_list, temp);
			memset(temp, 0, 64); //always clear buffer

			for (int i = 0; i < 5; i++){	//find all the occupied rooms
				//printf("DEBUG room in use: %i\n", room_in_use[i]);
				if(room_in_use[i] > 0){
					
					sprintf(temp, "\tRoom %i: %i\n", i, room_in_use[i]);	//add the rooms to a buffer to be sent
					strcat(room_list, temp);
					room_ocu = 1;

					//printf("DEBUG temp: %s\n", temp);
					//printf("DEBUG room_list: %s\n", room_list);

					memset(temp, 0, 64); //always clear buffer
				}
			}

			sprintf(temp, "Choose the room number or type [new] to create a new room: \n");
			strcat(room_list, temp);
			memset(temp, 0, 64); //always clear buffer			

			//if there were occupied rooms
			if(room_ocu == 1){	
				//printf("DEBUG: rooms are occupied\n");
				//cur = head;
				//while (cur != NULL) {	//find the requesting user
				//	if (cur->clisockfd == fromfd) {		
						//printf("dsihofghdsiuogfuioadshgf\n");
	
				//printf("DEBUG room_list: %s\n", room_list);
				//printf("DEBUG server socket: %i\n", cur->clisockfd);

				int nmsg = strlen(room_list);
						//int nsen = send(cur->clisockfd, room_list, nmsg, 0);	//send them the message with the list
				int nsen = send(fromfd, room_list, nmsg, 0);
				//	}
				memset(room_list, 0, 512); //always clear buffer
				//	cur = cur->next;
				//}
								
			} 
			//if there where no occupied rooms
			else {
				int index = -1;
				int i;
				//get first instance of 0
				for(i = 0; i < 5; i++){
					if(room_in_use[i] == 0){
						index = i;
						break;
					}
				} if (i == 5)	{
					printf("ERROR: No more rooms"); 
				}
				room_in_use[index] = 1;
				
				//add the user to first empty room
				cur = head;
				while (cur != NULL) {
					if (cur->clisockfd == fromfd) {
						cur->room_num = index;	//store nickname
					}
					cur = cur->next;
				}
			}
		}
	}

	//joining a room
	else if(strcmp(token, "join") == 0){	
		token = strtok(NULL, ":");	//get the nickname
		
		USR* cur = head;
		while (cur != NULL) {		//find the requesting user
			if (cur->clisockfd == fromfd) {
				//sprintf(cur->room_num, "%i", atoi(token));	//store their nickname
				cur->room_num = atoi(token);
			}
			cur = cur->next;
		}
		room_in_use[atoi(token)] += 1;
	}	 


	else {
		// traverse through all connected clients
		int sender_room;
		USR* cur = head;
		while (cur != NULL) {
			if (cur->clisockfd == fromfd) {
				sprintf(sender, "%s", cur->nickname);
				sender_room = cur->room_num;
			}
			cur = cur->next;
		}

		// traverse through all connected clients
		cur = head;
		while (cur != NULL) {
			// check if cur is not the one who sent the message
			if ((cur->clisockfd != fromfd) && (strlen(message) != 0) && (cur->room_num == sender_room)) {

				// prepare message
				//sprintf(buffer, "[%s]:%s", inet_ntoa(cliaddr.sin_addr), message);
				sprintf(buffer, "%s%s: %s\033[0;37m", color_options[cur->color], sender, message);
				int nmsg = strlen(buffer);

				// send!
				int nsen = send(cur->clisockfd, buffer, nmsg, 0);
			}

			memset(buffer, 0, 512); //always clear buffer
			cur = cur->next;
		}
	}

	/*for(int k = 0; k < 5; k++){
		printf("room in use: %i\t", room_in_use[k]);
	}printf("\n");*/

	memset(message, 0, 256); //always clear buffer
	memset(temp, 0, 256); //always clear buffer
	memset(buffer, 0, 512); //always clear buffer
	memset(room_list, 0, 512); //always clear buffer
}

typedef struct _ThreadArgs {
	int clisockfd;
} ThreadArgs;

void* thread_main(void* args)
{
	// make sure thread resources are deallocated upon return
	pthread_detach(pthread_self());

	// get socket descriptor from argument
	int clisockfd = ((ThreadArgs*) args)->clisockfd;
	free(args);

	//-------------------------------
	// Now, we receive/send messages
	char buffer[256];
	int nsen, nrcv;

	nrcv = recv(clisockfd, buffer, 255, 0);
	if (nrcv < 0) error("ERROR recv() failed");
		
	while (nrcv > 0){
		// we send the message to everyone except the sender
		broadcast(clisockfd, buffer);

		//printf("WHILE DEBUG: %s\n", buffer);


		nrcv = recv(clisockfd, buffer, 255, 0);
		if (nrcv < 0) error("ERROR recv() failed");
	}


	if(nrcv == 0){
		remove_node(&head, clisockfd);
		print_connections();
	}
	memset(buffer, 0, 256);

	close(clisockfd);
	//-------------------------------

	return NULL;
}

int main(int argc, char *argv[])
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) error("ERROR opening socket");

	struct sockaddr_in serv_addr;
	socklen_t slen = sizeof(serv_addr);
	memset((char*) &serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;	
	serv_addr.sin_port = htons(PORT_NUM);

	int status = bind(sockfd, 
			(struct sockaddr*) &serv_addr, slen);
	if (status < 0) error("ERROR on binding");

	listen(sockfd, 6); // maximum number of connections = 6

	while(1) {
		struct sockaddr_in cli_addr;
		socklen_t clen = sizeof(cli_addr);
		int newsockfd = accept(sockfd, 
			(struct sockaddr *) &cli_addr, &clen);
		if (newsockfd < 0) error("ERROR on accept");

		sprintf(serverIP, "%s", inet_ntoa(cli_addr.sin_addr));
		add_tail(newsockfd); // add this new client to the client list
		//print_connections();

		// prepare ThreadArgs structure to pass client socket
		ThreadArgs* args = (ThreadArgs*) malloc(sizeof(ThreadArgs));
		if (args == NULL) error("ERROR creating thread argument");
		
		args->clisockfd = newsockfd;

		pthread_t tid;
		if (pthread_create(&tid, NULL, thread_main, (void*) args) != 0) error("ERROR creating a new thread");
		
	}

	return 0; 
}

