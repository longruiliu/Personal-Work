#include"head.h"

int send_port;
int listen_port;
char send_ip[IP_LEN];
char rec_ip[IP_LEN];
char sdata1[LEN];
char sdata2[LEN];

void init_client()
{
	send_port = 8000;
	printf("Please input the ip of server.\n");
	scanf("%s",send_ip);
/*        printf("Please input data one:\n");
        scanf("%s",sdata1);
        printf("Please input data two:\n");
        scanf("%s",sdata2);*/
}

int main()
{
	pid_t re;
        init_client();
	int i;
	printf("Please input the initiate value of i:\n");
	scanf("%d",&i);
        re = fork();
        if (re < 0)
		printf("Can't create new process");
        else if (re == 0)
	{
		printf("process %d;i plus one\n",getpid());
		sleep(1);
		i++;
	}
	else 
	{
		printf("process %d;i minus one\n",getpid());
		sleep(1);
		i--;
	}
	send_data(i);

	return 0;
}
