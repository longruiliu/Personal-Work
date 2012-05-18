#ifndef HEAD
#define HEAD

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

#define LEN 1024
#define IP_LEN 15
#define P_LEN 5
#define R_PORT 8000
#define H_PORT 8500

char *check_tab(char *dip);
int char_int(char []);
void send_data(char *data,char ip[],int port);
int rec_connect(int);
void get_data(int);

#endif
