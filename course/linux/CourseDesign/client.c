#include"head.h"

char send_ip[IP_LEN];
int send_port;

void init()
{
	printf("Please input ip and port:\n");
	scanf("%s %d",send_ip,&send_port);
}

int main()
{
	int sendfd,success = 0;
	char buf[LEN];
	int do_what = 1;
	char user[STRING],passwd[STRING];
	init();
	printf("username:");
	scanf("%s",user);
	printf("password:");
	scanf("%s",passwd);
	
	buf[0] = do_what + '0';
	strcpy(buf + 1,user);
	buf[1 + strlen(user)] = '$';
	strcpy(buf + strlen(user) + 2,passwd);

	sendfd = send_connect(send_ip,send_port);
	write(sendfd,buf,LEN);
	read(sendfd,&success,sizeof(success));
	if (success == 1)
		printf("login success!\n");
	else
	{	
		printf("login error!\n");
		exit(0);
	}
	close(sendfd);

	while (1)
	{
		char command[STRING];
		printf("command:");
		scanf("%s",command);
		if (strcmp(command,"put") == 0)
			send_file(send_ip,send_port);
		else if (strcmp(command,"quit") == 0)
			break;
	}
	return 0;
}
