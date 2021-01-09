#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
//pton的简化实现，只支持ipv4
int inet_pton(int family, const char *strptr, void *addrptr){
	if(family == AF_INET){			//支持ipv4
		struct in_addr in_val;		//存放地址

		if(inet_aton(strptr,&in_val)){		//如果返回值为1，即字符串有效，将ASCII转换为二进制ipv4地址
			memcpy(addrptr , &in_val,sizeof(struct in_addr));	//将转换值复制到addrptr所指向的空间中
			return 1;						//返回1
		}
		return 0;							//如果字符串无效，返回0
	}
	errno = EAFNOSUPPORT;					//如果不是ipv4的地址族，errno设置为EAFNOSUPPORT，并返回-1
	return -1;
}

// //ntop的简化实现，只支持ipv4
// const char * inet_ntop(int family,const void *addrptr,char *strptr,size_t len){
// 	const u_char *p = (const u_char *) addrptr;		//将传入的二进制地址强制转换为无符号字符型
// 	if(family == AF_INET){				//支持ipv4
// 		char temp[INET_ADDRSTRLEN];		//一个大小为ipv4ASCII地址长度的数组。
// 		snprintf(temp,sizeof(temp),"%d.%d.%d.%d",p[0],p[1],p[2],p[3]);	//将转换后的地址输出，并拷贝至temp中

// 		if(strlen(temp) >=len ){	//若拷贝之后temp的长度大于len，则返回null，设置errorno为ENOSPC
// 			errno = ENOSPC;
// 			return NULL;
// 		}
// 		strcpy(strptr,temp);		//将temp拷贝至strptr并返回
// 		return strptr;
// 	}
// 	errno = EAFNOSUPPORT;			//若不是ipv4地址族则返回NULL，设置errno为EAFNOSUPPORT
// 	return NULL;
// }

char * sock_ntop(const struct sockaddr *sa,socklen_t salen){
	char portstr[8];
	static char str[128];		//unix缓冲区最大为128字节

	switch (sa->sa_family){		//在函数内进行协议族的判断
		case AF_INET:{			//ipv4协议族
			struct sockaddr_in *sin = (struct sockaddr_in *) sa; 	//将sa强制转换为sockaddr_in，方便提取端口号和地址。

			if(inet_ntop(AF_INET,&sin->sin_addr , str,sizeof(str)) == NULL){	//如果ntop出错，返回NULL
				return NULL;
			}
			if(ntohs(sin->sin_port)!=0){		//如果端口号不为0，将端口号由网络字节序转换为主机字节序后，输出端口号并拷贝至portstr
				snprintf(portstr,sizeof(portstr),":%d",ntohs(sin->sin_port));
				strcat(str,portstr);			//从str中删除端口号
			}
			return str;			//返回ip地址
		}

		case AF_INET6:{		//ipv6协议族
			struct sockaddr_in *sin = (struct sockaddr_in *) sa;
			if(inet_ntop(AF_INET6,&sin->sin_addr , str,sizeof(str)) == NULL){	//如果ntop出错，返回NULL
				return NULL;
			}
			if(ntohs(sin->sin_port)!=0){		//如果端口号不为0，将端口号由网络字节序转换为主机字节序后，输出端口号并拷贝至portstr
				snprintf(portstr,sizeof(portstr),":%d",ntohs(sin->sin_port));
				strcat(str,portstr);			//从str中删除端口号
			}
			return str;			//返回ip地址
		}
	}

	return NULL;
}