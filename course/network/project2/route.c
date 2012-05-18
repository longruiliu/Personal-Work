#include"head.h"

int init_route()
{
	int listen_port = R_PORT;

	return listen_port;
}

int main()
{
	int connfd,listenfd;
	int port;
	char *send_ip;
	char data[LEN];
	port = init_route();
	listenfd = rec_connect(port);
	connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	if (connfd >= 0)
		printf("Route connect OK!\n");
	while (read(connfd,data,LEN) > 0)
	{
		char s_ip[IP_LEN + 1],d_ip[IP_LEN + 1];
		memcpy(s_ip,data,IP_LEN);
		memcpy(d_ip,data + IP_LEN,IP_LEN);
		for (int i = 0;i < IP_LEN;i++)
			if (s_ip[i] == '$')
			{
				s_ip[i] = '\0';
				break;
			}
		s_ip[IP_LEN] = '\0';
		for (int i = 0;i < IP_LEN;i++)
			if (d_ip[i] == '$')
			{
				d_ip[i] = '\0';
				break;
			}
		d_ip[IP_LEN] = '\0';
		printf("**********source IP               destination IP***************\n");
		printf("          %s               %s                            \n",s_ip,d_ip);

		send_ip = check_tab(d_ip);//check the routing table.
		if (strcmp(send_ip,"127.0.0.1") == 0)
			send_data(data,send_ip,H_PORT);
		else
			send_data(data,send_ip,R_PORT);
		close(connfd);
		data[0] = '\0';

		connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	}
}
