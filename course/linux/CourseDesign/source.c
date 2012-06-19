#include"head.h"

int send_connect(char send_ip[IP_LEN],int send_port)
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

int listen_connect(int port)
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

void create_user()
{
	FILE *fin = NULL;
	if ((fin = fopen("user.conf","w+")) == NULL)
	{
		printf("Can't open the user file!\n");
		exit(0);
	}
	char name[STRING],passwd[STRING];
	int power;
	printf("Please input the name,passwd and power of th new user\n");
	scanf("%s %s %d",name,passwd,&power);
	fprintf(fin,"%s %s %d\n",name,passwd,power);
	fclose(fin);
}

void get_command()
{
	char command[STRING];
	printf("Command:");
	scanf("%s",command);
	if (strcmp(command,"rename") == 0)
	{
		char name1[STRING],name2[STRING];
		printf("Please input the old name and new name:\n");
		scanf("%s %s",name1,name2);
		rename(name1,name2);
	}
	else if (strcmp(command,"delete") == 0)
	{
		char name[STRING];
		printf("Please input the file you want to delete:\n");
		scanf("%s",name);
		remove(name);
	}
	else 
		printf("Can't find the command\n");
}

void interaction(int listen_port)
{
	int connfd,listenfd;
	int power;
	int do_what;
	listenfd = rec_connect(listen_port);
	connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	while (read(connfd,&do_what,sizeof(do_what)) > 0)
	{
		if (do_what == 1)
		{
			char user[STRING],passwd[STRING];
			char one[STRING],two[STRING];
			if (read(connfd,user,STRING)&&read(connfd,passwd,STRING))
			{
				FILE *fin;
				int success = 0;
				if ((fin = fopen("user.conf","r")) == NULL)
				{
					printf("Open file error\n");
					break;
				}
				while (fscanf(fin,"%s %s %d",one,two,&power))
					if (strcmp(user,one) == 0&&strcmp(passwd,two))
						success = 1;
				write(connfd,&success,sizeof(success));

			}
			else 
			{
				printf("get user error!\n");
				break;
			}
		}
	}
	return 0;
}
