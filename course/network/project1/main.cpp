#include"head.h"
int listen_port;
int send_port;
char local_ip[20] = "192.169.1.1";
char send_ip[20] = "192.168.1.2";

int main()
{
	listen_port = 8000;
	send_port = 1234;
	char d[] = "I am the king of the world!";
	string data(d);
	trans test1(data);
	cout<<test1.val()<<endl;

        IP test2(test1.val());

	cout<<"test"<<endl;
	test2.test();
	printf("The length is:%d\n",test2.length());
	printf("The data are:\n");
	test2.print();

	return 0;
}
