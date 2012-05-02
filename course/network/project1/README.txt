头文件head.h

定义常量MAXLENGTH,FRAME_LEN,PRE_SUF_LEN,IP_LEN分别表示总数据长度，ip段数据长度，前缀和后缀长度，ip地址长度

变量listen_port：服务端监听的端口
变量send_port:发送数据是从哪个端口发送的
变量local_ip：本机ip地址
变量send_ip:要发往的ip地址
变量smac：本机mac地址
变量dmac:目标主机mac地址
变量s_data:要发送的原始数据
变量total_frame：数据在ip层公分成多少个包
变量buf:缓存数据的变量
变量send_addr和rec_addr是发送和接收套接字要用到的数据结构

函数init()是对端口，ip地址，mac地址和原始数据进行初始化
函数send_data()和rec_data()分别是发送数据和接收数据的函数
函数send_connect()和rec_connect()分别是建立发送和接收套接字的连接

后面是每个类的声明，成员函数均在此处



main.cpp
通过choice选择是什么角色
发送数据是作为客户端
接收数据是作为服务器端
