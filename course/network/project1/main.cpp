#include"head.h"

int listen_port;
int send_port;
string local_ip;
string send_ip;
string smac;
string dmac;
string s_data;
unsigned int total_frame;
struct sockaddr_in send_addr;
struct sockaddr_in rec_addr;
char buf[MAXLENGTH];

int main()
{
	int choice = 0;
	printf("Please choose your role:\n1..............sender\n2..............receiver\nother..........exit\n",&choice);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		        init();
			send_data();
			break;
		case 2:
		        init();
			rec_data();
			break;
		default:
			break;
	}

	return 0;
}
