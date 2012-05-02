#include"head.h"

TRANS::TRANS(string str)
{
	_s_port = listen_port;
	_d_port = send_port;
	char tmp[PRE_SUF_LEN];
	sprintf(tmp,"%05d",_s_port);
	string tmp1(tmp);
	_data += tmp1;
	sprintf(tmp,"%05d",_d_port);
	string tmp2(tmp);
	_data += tmp2;
	_data += str;
	_length = _data.length();
}

IP::IP(string str)
{
	while (local_ip.length() != IP_LEN)
		local_ip += "$";
	while (send_ip.length() != IP_LEN)
		send_ip += "$";
	_data += local_ip;
	_data += send_ip;
	_data += str;
	_length = _data.length();
}

LINK::LINK(string str)
{
	_tail = "11111";
	_s_mac += smac;
	_d_mac += dmac;
	_data += _s_mac;
	_data += _d_mac;
	_data += str;
	_data += _tail;
	_length =_data.length();
}

PHY::PHY(string str)
{
	_head = "00000";
	_data += _head;
	_data += str;
	_length = _data.length();
}

//change the physical data to hexadecimal.
void binary(string str)
{
	for (int i = 0;i < str.length();i++)
		printf("%x",str[i]);
	printf("\n");
}

//initiate port,ip,mac.
void init()
{
	listen_port = 8000;
	send_port = 8000;
	local_ip = "255.255.25.21";
	send_ip = "127.0.0.1";
	smac = "BBBBBBBBBBBB";
	dmac = "DDDDDDDDDDDD";
	s_data = "I am the king of the world!";
	total_frame = (s_data.length() + 2 * PRE_SUF_LEN) / FRAME_LEN + 1;
}

void send_data()
{
	int send_connect();
	int sendfd;

	//send sum of the frames.
	sendfd = send_connect();
	write(sendfd,&total_frame,sizeof(total_frame));
	close(sendfd);


	cout<<"The source data:\n"<<s_data<<endl;

	//source and transpotation data.
	string data(s_data);
	TRANS test1(data);
	cout<<"TRANS:";
	test1.print();

	for (int i = 0;i < total_frame;i++)
	{
	        sendfd = send_connect();

		string tmp;
		tmp.assign(test1.val(),i * FRAME_LEN,FRAME_LEN);   //divide the data into frames.
        	IP test2(tmp);
		test2.set_order(i + 1);
		LINK test3(test2.val());
		PHY test4(test3.val());
		printf("%d/%d\n",test2.order(),total_frame);

		cout<<"IP:";
		test2.print();

		cout<<"LINK:";
		test3.print();

		cout<<"PHY:";
		binary(test4.val());

		string res = test4.val();
		int i = 0;
		for (i = 0;i < test4.length();i++)
			buf[i] = res[i];
		buf[i] = '\0';

		//write data to socket
		write(sendfd,(char*)buf,sizeof(buf));
		close(sendfd);
	}
}

int send_connect()
{
	int fd;
	int n;
	if ((fd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		printf("socket error!\n");
		exit(0);
	}
	bzero(buf,sizeof(buf));
	send_addr.sin_family = AF_INET;
	send_addr.sin_port = htons((unsigned short)send_port);
	char ip[IP_LEN];
	for (int i = 0;i < send_ip.length();i++)
		ip[i] = send_ip[i];
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

int rec_connect()
{
	int listenfd,opt;
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

	if (listen(listenfd,MAXLENGTH) < 0)
	{
		printf("listen error!\n");
		exit(0);
	}

	return listenfd;
}


void rec_data()
{
	int connfd,listenfd,total;
	string res;
	listenfd = rec_connect();

	//receive the sum of frames.
	connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	read(connfd,&total,sizeof(total));
	printf("There are %d frames.\n",total);
	close(connfd);

	for (int i = 0;i < total;i++)
	{
		connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
		if (read(connfd,(char *)buf,MAXLENGTH) > 0)
		{
			string tmp(buf);
			cout<<i+1<<'/'<<total<<endl;
			cout<<"PHY:";
			binary(tmp);

			tmp.assign(tmp,PRE_SUF_LEN,string::npos);     //cut the prefix of PHY
			cout<<"LINK:"<<tmp<<endl;

			tmp.assign(tmp,0,tmp.length() - PRE_SUF_LEN); //cut the prefix and suffix of LINK
			tmp.assign(tmp,24,string::npos);
			cout<<"IP:"<<tmp<<endl;

			tmp.assign(tmp,2 * IP_LEN,string::npos);      //cut the prefix of IP
			res += tmp;

		}
		else 
			printf("receive data error!\n");
		close(connfd);
	}
	cout<<"TRANS:"<<res<<endl;
	res.assign(res,2 * PRE_SUF_LEN,string::npos);

	cout<<"The source data are:\n"<<res<<endl;
}
