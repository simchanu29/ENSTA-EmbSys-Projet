/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>


/*
Compilation sans librairie
lancer d'abord le serveur puis le client dans 
deux terminals différents avec les commandes:
./server 51717
./client localhost 51717

(si les executables s'appellent client et server
*/



void erreur(const char *msg)
{
    perror(msg);
    exit(1);
}




int main(int argc, char *argv[])
{
    int sockfd=-1, newsockfd=-1, portno;
	socklen_t clilen;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	int tour=0;
    char reponse[256];
     
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     portno = atoi(argv[1]);
	
	 sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
         erreur("ERROR opening\n");
         
     //if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
     //	error("setsockopt(SO_REUSEADDR) failed");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
	 if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0)
              	erreur("ERROR on binding\n");
     
     
     
     while(1){
     	tour++;
     	usleep(20000);
     	
     	listen(sockfd,5);
     	clilen = sizeof(cli_addr);
     	newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     	if (newsockfd < 0){
         	printf("ERROR on accept\n");
     	}
     	
     	bzero(buffer,256);
     	n = read(newsockfd,buffer,255);
     	
     	printf("Here is the message: %s\n",buffer);
     	sprintf(reponse, "I got your message %d",tour);
     	n = write(newsockfd,reponse,strlen(reponse));
     	
     }
     close(newsockfd);
     close(sockfd);
     return 0; 
}








