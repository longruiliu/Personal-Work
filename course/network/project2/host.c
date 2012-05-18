#include"head.h"

int init_rec()
{
	int listen_port = H_PORT;

	return listen_port;
}

char *init_send(char ip[],int *port)
{
	int local_port = 8000;
	int length,i;
	*port = 8000;
	char dtmp[LEN];
	static char data[LEN];
	char ptmp[P_LEN + 1],local_ip[IP_LEN + 1];
	printf("Please input the ip of the host you want to send data:\n");
	scanf("%s",ip);
	printf("Please input the local ip:\n");
	scanf("%s",local_ip);

        //add the ip address to 15 bytes.
	length = strlen(ip);
	for (i = length;i < IP_LEN;i++)
		ip[i] = '$';
	length = strlen(local_ip);
	for (i = length;i < IP_LEN;i++)
		local_ip[i] = '$';

	//make up the datagram.
	printf("Please input the data you want to send:\n");
	scanf("%s",dtmp);
	length = strlen(dtmp) + 1;
	memcpy(data,local_ip,IP_LEN);
	memcpy(data + IP_LEN,ip,IP_LEN);
	sprintf(ptmp,"%05d",local_port);
	memcpy(data + 2 * IP_LEN,ptmp,P_LEN);
	sprintf(ptmp,"%05d",*port);
	memcpy(data + 2 * IP_LEN + P_LEN,ptmp,P_LEN);
	memcpy(data + 2 * IP_LEN + 2 * P_LEN,dtmp,length);
	data[2 * (IP_LEN + P_LEN) + length] = '\0';

	return data;
}

int main()
{
	int choice = 0;
	int listen_port,send_port;
	int listenfd;
	char send_ip[IP_LEN];
	char route_ip[] = "127.0.0.1";
	char *data;
	printf("Please choose your role:\n1..............sender\n2..............receiver\nother..........exit\n",&choice);
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		        data = init_send(send_ip,&send_port);
			send_data(data,route_ip,R_PORT);
			break;
		case 2:
		        listen_port = init_rec();
			get_data(listen_port);
			break;
		default:
			break;
	}
	return 0;
}

