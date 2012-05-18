#include"head.h"

void send_data(int tmp)
{
	int send_connect();
	int sendfd;
	int length;

	sendfd = send_connect();
	write(sendfd,&tmp,sizeof(tmp));
	close(sendfd);
}

int send_connect()
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
	send_addr.sin_port = htons((unsigned short)send_port);
	if (inet_pton(AF_INET,send_ip,&send_addr.sin_addr) < 0)
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

int rec_connect()
{
	int listenfd,opt;
	struct sockaddr_in rec_addr;
	int port = listen_port;

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

