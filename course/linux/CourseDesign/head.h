#ifndef HEAD
#define HEAD
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<strings.h>
#include<ctype.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define LEN 512
#define IP_LEN 16
#define STRING 20

int send_connect(char[],int);
int listen_connect(int);

void create_user();
void get_command();
int interaction(int,int *);
void s_get_client(int,int);
void c_send_file(char [],int);
void c_get_file(char[],int);
void list_file(char [],int);
void c_end(char[],int);

extern int send_port;       //the port want to send message
extern char send_ip[IP_LEN];      //the ip you want to send message
extern struct sockaddr_in send_addr,rec_addr;

#endif

