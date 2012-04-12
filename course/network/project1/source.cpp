#include"head.h"

trans::trans(string str)
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
	char tmp1[IP_LEN];
	sprintf(tmp1,"%15s",local_ip);
	string tmp2(tmp1);
	_data += tmp2;
	char tmp3[IP_LEN];
	sprintf(tmp3,"%15s",send_ip);
	string tmp4(tmp3);
	_data += tmp4;
	_data += str;
	_length = _data.length();

	cout<<_data<<endl;
}
