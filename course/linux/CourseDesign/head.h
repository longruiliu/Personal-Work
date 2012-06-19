#ifndef HEAD
#define HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define LEN 1024
#define IP_LEN 16
#define STRING 20

int send_connect(char[],int);
int listen_connect(int);

void create_user();
void get_command();
void interaction(int);

extern int listen_port;     //the port host are listening
extern int send_port;       //the port want to send message
extern char  local_ip[IP_LEN];     //host ip
extern char send_ip[IP_LEN];      //the ip you want to send message
extern struct sockaddr_in send_addr,rec_addr;

#endif

