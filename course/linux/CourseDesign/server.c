#include"head.h"

int listen_port;

void init()
{
	printf("Please input the listen port:\n");
	scanf("%d",&listen_port);
}

int main()
{
	int do_what;
	while (1)
	{
		printf("Please choose what to do:\n1--------->create a new user\n2--------->start server\n3--------->input command\n4--------->exit\n");
		scanf("%d",&do_what);
		switch (do_what)
		{
			case 1:
				create_user();
				break;
			case 2:
				init();
				interaction(listen_port);
				break;
			case 3:
				get_command();
				break;
			case 4:
				exit(0);
		}
	}

}
