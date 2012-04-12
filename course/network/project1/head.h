#ifndef NET
#define NET
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
using namespace std;

#define MAXLENGTH 1024
#define FRAME_LEN 100       //the length of datagram
#define PRE_SUF_LEN 5       //the length of prefix or suffix
#define IP_LEN 20           //the length of ip address

extern int listen_port;             //the port host are listening
extern int send_port;               //the port want to send message
extern char local_ip[20];           //host ip
extern char send_ip[20];            //the ip you want to send message

class trans
{
	private:
	unsigned int _s_port;
	unsigned int _d_port;
	unsigned int _length;
	string _data;
	public:
	trans(string);
	inline int length()
	{
		return _length;
	}
	inline void print()
	{
		cout<<_data<<endl;
	}
	inline string &val()
	{
		return _data;
	}
};

class IP
{
	private:
	int _order;
	unsigned int _length;
	string _data;
	public:
	IP(string);
	inline int length()
	{
		return _length;
	}
	inline void print()
	{
		cout<<_data<<endl;
	}
	inline void set_order(int tmp)
	{
		_order = tmp;
	}
	inline void test()
	{
		cout<<"test"<<endl;
	}
};
#endif
