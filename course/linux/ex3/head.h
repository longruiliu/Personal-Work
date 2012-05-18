#ifndef HEAD
#define HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define LEN 1024
#define IP_LEN 16

int send_connect();
int rec_connect();
void send_data(int);
void rec_data();

extern int listen_port;     //the port host are listening
extern int send_port;       //the port want to send message
extern char  local_ip[IP_LEN];     //host ip
extern char send_ip[IP_LEN];      //the ip you want to send message
extern struct sockaddr_in send_addr,rec_addr;

#endif
