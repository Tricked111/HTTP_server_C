#include "net.h"


typedef enum{

    SOCKET_ERR   = -1,
    SETSSOCK_ERR = -2,
    BIND_ERR     = -3,
    LISTEN_ERR   = -4,
    CONNECT_ERR  = -5,
}error_t;

//function create new_socket and setting to listening mode
int Socket(char *port){ 

    int serverSocket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); //create new socket for connection
    if(serverSocket < 0)
    return SOCKET_ERR;
    
    if(setsockopt(serverSocket,SOL_SOCKET,SO_REUSEADDR,&(int){1},sizeof(int)) < 0) //if the socket has been used previously and is busy
    return SETSSOCK_ERR;
                                                            //127.0.0.1:8080           
    struct sockaddr_in addr;                                //set param for socket                   
    addr.sin_family = AF_INET;                              //type conn            
    addr.sin_port = htons(atoi(port));                      //port    
    addr.sin_addr.s_addr = INADDR_ANY;                      //IPv4

    if(bind(serverSocket,(struct sockaddr *) &addr,sizeof(addr)) != 0)  //connect struct with socket 
    return BIND_ERR;
    
    if(listen(serverSocket,SOMAXCONN) != 0)                 //server is listening    
    return LISTEN_ERR;

    return serverSocket;                                    //return Socket  
}

//socket accept new user 
int Accept(int serverSocket){
    return accept(serverSocket,NULL,NULL);
}
//close socket
int Close(int net){
    return close(net);
}
//send socket
int Send(int net,char *buffer,size_t size){
    return send(net,buffer,(int)size,0);
}
//recv socket
int Recv(int net,char *buffer,size_t size){
    return recv(net,buffer,(int)size,0);
}
//send http response
void send_http(int userSocket,char* headder,char *request){
     
    FILE *file = popen(request,"r");
    char pathh[256];
    
    fgets(pathh,256,file);

    strcat(headder,pathh);
    ssize_t size = strlen(headder);

    Send(userSocket,headder,size);
    
    fclose(file);
    Close(userSocket);
}
//parse http request
void parse_http(int userSocket,char *headder,char *buff){
    if(strstr(buff,"load") != NULL){
        send_http(userSocket,headder,"bash cpu_usage.sh");
    }
    else if(strstr(buff,"cpu-name") != NULL){
        send_http(userSocket,headder,"bash cpu_name.sh");
    }
    else if(strstr(buff,"hostname") != NULL){
       send_http(userSocket,headder,"hostname");
    }
    else if(strstr(buff,"date") != NULL){
       send_http(userSocket,headder,"date");
    }
    else if(strstr(buff,"/ ") != NULL){
        send_http(userSocket,headder,"echo Welcome!!!");
    }
    else{
        send_http(userSocket,headder,"echo 404 Error Page not found");
    }
}
//set port from argv
int set_port(int argc, char *argv[],char *port){
    if((argc > 2 || argc < 2)  || (strlen(argv[1]) < 4 || strlen(argv[1]) > 5))
    return 0;
    
    strcpy(port,argv[1]);
    return 1;
}
