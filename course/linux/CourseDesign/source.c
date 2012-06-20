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

int interaction(int listen_port,int *listenfd)
{
	int connfd;
	int power;
	char buf[LEN];
	int do_what;

	bzero(buf,LEN);
	*listenfd = listen_connect(listen_port);
	connfd = accept(*listenfd,(struct sockaddr*)NULL,NULL);
	if (read(connfd,buf,LEN) > 0)
	{
		do_what = buf[0] - '0';
		if (do_what == 1)
		{
			char user[STRING],passwd[STRING];
			char one[STRING],two[STRING];
			int i,j;
			for (i = 1;i < strlen(buf);i++)
			{
				if (buf[i] == '$')
					break;
				user[i - 1] = buf[i];
			}
			user[i - 1] = '\0';
			for (j = 0;i < strlen(buf);i++,j++)
				passwd[j] = buf[i + 1];
			passwd[j] = '\0';	
			FILE *fin;
			int success = 0;
			if ((fin = fopen("user.conf","r")) == NULL)
			{
				printf("Open file error\n");
				return -1;
			}
			while (fscanf(fin,"%s %s %d",one,two,&power) == 3)
				if (strcmp(user,one) == 0&&strcmp(passwd,two) == 0)
					success = 1;
			write(connfd,&success,sizeof(success));
		}
	}
	close(connfd);
	return power;
}
void send_file(char send_ip[LEN],int send_port)
{
	char name[STRING];
	int sendfd;
	char buf[LEN];
	FILE *fin = NULL;
	printf("Please input the file name:");
	scanf("%s",name);
	bzero(buf,LEN);
	buf[0] = '1';
	strcpy(buf + 1,name);
	
	sendfd = send_connect(send_ip,send_port);
	printf("I am here\n");
	write(sendfd,buf,LEN);
	close(sendfd);

	sendfd = send_connect(send_ip,send_port);
	fin = fopen(name,"rb");
	if (fin == NULL)  
        {  
            printf("File:\t%s Not Found!\n",name);  
        }  
        else  
        {  
            bzero(buf, LEN);  
            int length = 0;  
            while( (length = fread(buf, sizeof(char),LEN, fin)) > 0)  
            {  
                printf("length = %d\n",length);  
  
                // 发送buf中的字符串到sendfd,实际上就是发送给服务器端 
                if (send(sendfd, buf,length, 0) < 0)  
                {  
                    printf("Send File:\t%s Failed!\n",name);  
                    break;  
                }  
  
                bzero(buf, sizeof(buf));  
            }  
            fclose(fin);  
            printf("File:\t%s Transfer Finished!\n",name); 
	} 
}

void get_file(int listenfd,char filename[STRING])
{
	system("pwd");
	printf("filename:%s",filename);
	FILE *fout = fopen(filename,"wb");
	char buf[LEN];
	int connfd;
    	int length = 0;  

        bzero(buf, LEN);  
	connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
    	while(length = recv(connfd, buf,LEN, 0)) 
	{	
        	if (length < 0)  
        	{  
			printf("Recieve Data From client Failed!\n");  
			break;  
		}
  
        	int write_length = fwrite(buf, sizeof(char), length,fout);  
        	if (write_length < length)  
        	{  
            		printf("File:\t%s Write Failed!\n",filename);  
            		break;  
        	}  
        	bzero(buf,LEN);  
	}  
  
	printf("Recieve File:\t %s From client Finished!\n",filename);  
  
    	// 传输完毕，关闭socket  
    	fclose(fout);  
    	close(connfd);  
}

void get_client(int power,int listenfd)
{
	int connfd;
	int do_what;
	char buf[LEN];
	char argument[STRING];
	system("cd director");
	bzero(buf,LEN);
	connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);

	while (read(connfd,buf,LEN) > 0)
	{
		do_what = buf[0] - '0';
		for (int i = 1;i < strlen(buf);i++)
		{
			if (buf[i] == '$')
				break;
			argument[i - 1] = buf[i];
		}
		if (do_what == 1)
		{
			close(connfd);
			get_file(listenfd,argument);
		}
	}
}
