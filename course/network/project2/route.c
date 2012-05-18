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
		char tmp_ip[IP_LEN];
		memcpy(tmp_ip,data + IP_LEN,IP_LEN);
		for (int i = 0;i < IP_LEN;i++)
			if (tmp_ip[i] == '$')
			{
				tmp_ip[i] = '\0';
				break;
			}
		send_ip = check_tab(tmp_ip);//check the routing table.
		if (strcmp(send_ip,"127.0.0.1") == 0)
			send_data(data,send_ip,H_PORT);
		else
			send_data(data,send_ip,R_PORT);
		close(connfd);
		data[0] = '\0';

		connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	}
}
