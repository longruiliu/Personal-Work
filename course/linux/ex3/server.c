#include"head.h"

int listen_port;
int send_port;
char send_ip[IP_LEN];
char rec_ip[IP_LEN];

void init_server()
{
	listen_port = 8000;
}

int main()
{
	int connfd,listenfd;
	int res = 0;
	init_server();
	listenfd = rec_connect();
	connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	while (read(connfd,&res,sizeof(res)) > 0)
	{
		printf("The data are:%d\n",res);
	        close(connfd);
	        connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
		res = 0;
	}
	return 0;
}
