#ifndef NET
#define NET
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<bitset>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
using namespace std;

#define MAXLENGTH 1024
#define FRAME_LEN 20        //the length of datagram
#define PRE_SUF_LEN 5       //the length of prefix or suffix
#define IP_LEN 15           //the length of ip address

extern int listen_port;     //the port host are listening
extern int send_port;       //the port want to send message
extern string local_ip;     //host ip
extern string send_ip;      //the ip you want to send message
extern string smac;         //the source mac address
extern string dmac;         //the destination mac address
extern string s_data;       //the source data
extern unsigned int total_frame; // the sum of frames
extern char buf[MAXLENGTH];
extern struct sockaddr_in send_addr;
extern struct sockaddr_in rec_addr;

void init();           //initiate port,ip,mac
void send_data();      //send data
void rec_data();       //receive data
int send_connect();    //set up a sender socket(as client)
int rec_connect();    //set up a receiver socket(as server)

class TRANS
{
	private:
	unsigned int _s_port;
	unsigned int _d_port;
	unsigned int _length;
	string _data;
	public:
	TRANS(string);
	inline int length()
	{
		return _length;
	}
	inline unsigned int s_port()
	{
		return _s_port;
	}
	inline unsigned int d_port()
	{
		return _d_port;
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
	inline int order()
	{
		return _order;
	}
	inline void print()
	{
		cout<<_data<<endl;
	}
	inline void set_order(int tmp)
	{
		_order = tmp;
	}
	inline string &val()
	{
		return _data;
	}	
};

class LINK
{
	private:
	string _s_mac;
	string _d_mac;
	unsigned int _length;
	string _tail;
	string _data;
	public:
	LINK(string);
	inline string s_mac()
	{
		return _s_mac;
	}
	inline string d_mac()
	{
		return _d_mac;
	}
	inline unsigned int length()
	{
		return _length;
	}
	inline string tail()
	{
		return _tail;
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

class PHY
{
	private:
	string _head;
	string _data;
	int _length;
	public:
	PHY(string);
	inline void print()
	{
		cout<<_data<<endl;
	}
	inline int length()
	{
		return _length;
	}
	inline string &val()
	{
		return _data;
	}
};
#endif
