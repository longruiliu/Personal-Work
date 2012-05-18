#include"head.h"

char *check_tab(char *dip)
{
	static char first[IP_LEN + 1],second[IP_LEN + 1];
	freopen("route.conf","r",stdin);

	printf("The route table are:\n");
	while (scanf("%s %s",first,second) == 2)
		printf("%s            %s\n",first,second);

	freopen("route.conf","r",stdin);
	while (scanf("%s %s",first,second) == 2)
	{
		if (strcmp(dip,first) == 0)
			break;
	}
	printf("Find the next hop:%s\n",second);
	return second;
}

int char_int(char tmp[])
{
	int i,sum = 0;
	for (i = 0;i < P_LEN;i++)
	{
		sum *= 10;
		sum += (tmp[i] - '0');
	}
	return sum;
}

void send_data(char *data,char ip[],int port)
{
	int send_connect(char ip[],int port);
	int sendfd;
	int length = strlen(data) + 1;

	sendfd = send_connect(ip,port);
	write(sendfd,data,length);
	close(sendfd);

	printf("Send data successful!\n");
}

int send_connect(char ip[],int port)
{
	int fd;
	int n;
	struct sockaddr_in send_addr;
	if ((fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("socket error!\n");
		exit(0);
	}
	send_addr.sin_family = AF_INET;
	send_addr.sin_port = htons((unsigned short)port);
	if (inet_pton(AF_INET,ip,&send_addr.sin_addr) < 0)
	{
		printf("inet_pton error!\n");
		exit(0);
	}
	if ((n = connect(fd,(struct sockaddr *)&send_addr,sizeof(send_addr))) < 0)
	{
		printf("connect error!\n");
		exit(0);
	}

	return fd;
}

int rec_connect(int port)
{
	int listenfd,opt;
	struct sockaddr_in rec_addr;

	if ((listenfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("socket error!\n");
		exit(0);
	}

	if (setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,(const void*)&opt,sizeof(opt)) < 0)
	{
		printf("setsocket error!\n");
		exit(0);
	}

	bzero(&rec_addr,sizeof(rec_addr));
        rec_addr.sin_family = AF_INET;
	rec_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	rec_addr.sin_port = htons((unsigned short)port);
	if (bind(listenfd,(struct sockaddr*)&rec_addr,sizeof(rec_addr)) < 0)
	{
		printf("setsock error!\n");
		exit(0);
	}

	if (listen(listenfd,LEN) < 0)
	{
		printf("listen error!\n");
		exit(0);
	}

	return listenfd;
}

void get_data(int listen_port)
{
	int connfd,listenfd;
	char data[LEN];
	listenfd = rec_connect(listen_port);
	connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	if (connfd >= 0)
		printf("host connect OK!\n");
	while (read(connfd,data,LEN) > 0)
	{
		int length = strlen(data) + 1;
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

		printf("The data are:");
		for (int i = 2 * (IP_LEN + P_LEN);i < length;i++)
			printf("%c",data[i]);
		printf("\n");
		close(connfd);
		data[0] = '\0';
		
		connfd = accept(listenfd,(struct sockaddr *)NULL,NULL);
	}
}
