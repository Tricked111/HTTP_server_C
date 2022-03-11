#include <stdio.h>
#include "net.h"

int main(int argc, char *argv[]){

    //checking for errors in the port
    if(!(set_port(argc,argv,port))){
        printf("Error port\n");
        return 0;
    } 

    //create socket
    int serverSocket = Socket(port);

    //request acceptance cycle
    while(1){
    int userSocket = Accept(serverSocket);
    char headder[48] = ("HTTP/1.1 200 OK\r\nContent-type: text/plain;\r\n\r\n");
    Recv(userSocket,buff,BUFFER_SIZE);
    parse_http(userSocket,headder,buff);
    }
    
    //close server
    Close(serverSocket);
    return 0;
}