#ifndef LIB_NET_H
#define LIB_NET_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 300


char buff[BUFFER_SIZE];
char port[6];


int Socket(char *port);
int Accept(int serverSocket);
int Connect(char *port);
int Close(int userSocket);


int Send(int userSocket,char *buffer,size_t size);
int Recv(int userSocket,char *buffer,size_t size);

int set_port(int argc, char *argv[],char *port);

void parse_http(int userSocket,char *headder,char *buff);
void send_http(int userSocket,char* headder,char *request);

#endif  //LIB_NET_H