#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

/**
 * Methode de gestion d'erreur.
 * @param msg
 */
void error(const char *msg)
{
    perror(msg);
    exit(0);
}

/**
 * Envoie de manière unique la string qu'on lui a envoyé en argument.
 *
 * USAGE :
 * lancer d'abord le serveur puis le client.
 * ./main-client.out host message
 *
 * EXEMPLE :
 * ./main-client.out localhost hello_world!
 *
 * @param argc
 * @param argv : host message
 * @return
 */
int main(int argc, char *argv[])
{
    // Initialisation
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];


    // Gestion des arguments du main
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname message [port]\n", argv[0]);
        exit(0);
    } else if(argc == 3){
        portno = 51717;
    } else{
        portno = atoi(argv[3]);
    }

    // Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Host
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Set up connection
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connection
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Set up string to send
    bzero(buffer,256);
    sprintf(buffer,argv[3]);

    // Send string to server
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");
    bzero(buffer,256);

    // Receive string from server
    n = read(sockfd,buffer,255);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n",buffer);

    close(sockfd);
    return 0;
}
