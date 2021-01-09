#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
//pton�ļ�ʵ�֣�ֻ֧��ipv4
int inet_pton(int family, const char *strptr, void *addrptr){
	if(family == AF_INET){			//֧��ipv4
		struct in_addr in_val;		//��ŵ�ַ

		if(inet_aton(strptr,&in_val)){		//�������ֵΪ1�����ַ�����Ч����ASCIIת��Ϊ������ipv4��ַ
			memcpy(addrptr , &in_val,sizeof(struct in_addr));	//��ת��ֵ���Ƶ�addrptr��ָ��Ŀռ���
			return 1;						//����1
		}
		return 0;							//����ַ�����Ч������0
	}
	errno = EAFNOSUPPORT;					//�������ipv4�ĵ�ַ�壬errno����ΪEAFNOSUPPORT��������-1
	return -1;
}

// //ntop�ļ�ʵ�֣�ֻ֧��ipv4
// const char * inet_ntop(int family,const void *addrptr,char *strptr,size_t len){
// 	const u_char *p = (const u_char *) addrptr;		//������Ķ����Ƶ�ַǿ��ת��Ϊ�޷����ַ���
// 	if(family == AF_INET){				//֧��ipv4
// 		char temp[INET_ADDRSTRLEN];		//һ����СΪipv4ASCII��ַ���ȵ����顣
// 		snprintf(temp,sizeof(temp),"%d.%d.%d.%d",p[0],p[1],p[2],p[3]);	//��ת����ĵ�ַ�������������temp��

// 		if(strlen(temp) >=len ){	//������֮��temp�ĳ��ȴ���len���򷵻�null������errornoΪENOSPC
// 			errno = ENOSPC;
// 			return NULL;
// 		}
// 		strcpy(strptr,temp);		//��temp������strptr������
// 		return strptr;
// 	}
// 	errno = EAFNOSUPPORT;			//������ipv4��ַ���򷵻�NULL������errnoΪEAFNOSUPPORT
// 	return NULL;
// }

char * sock_ntop(const struct sockaddr *sa,socklen_t salen){
	char portstr[8];
	static char str[128];		//unix���������Ϊ128�ֽ�

	switch (sa->sa_family){		//�ں����ڽ���Э������ж�
		case AF_INET:{			//ipv4Э����
			struct sockaddr_in *sin = (struct sockaddr_in *) sa; 	//��saǿ��ת��Ϊsockaddr_in��������ȡ�˿ںź͵�ַ��

			if(inet_ntop(AF_INET,&sin->sin_addr , str,sizeof(str)) == NULL){	//���ntop��������NULL
				return NULL;
			}
			if(ntohs(sin->sin_port)!=0){		//����˿ںŲ�Ϊ0�����˿ں��������ֽ���ת��Ϊ�����ֽ��������˿ںŲ�������portstr
				snprintf(portstr,sizeof(portstr),":%d",ntohs(sin->sin_port));
				strcat(str,portstr);			//��str��ɾ���˿ں�
			}
			return str;			//����ip��ַ
		}

		case AF_INET6:{		//ipv6Э����
			struct sockaddr_in *sin = (struct sockaddr_in *) sa;
			if(inet_ntop(AF_INET6,&sin->sin_addr , str,sizeof(str)) == NULL){	//���ntop��������NULL
				return NULL;
			}
			if(ntohs(sin->sin_port)!=0){		//����˿ںŲ�Ϊ0�����˿ں��������ֽ���ת��Ϊ�����ֽ��������˿ںŲ�������portstr
				snprintf(portstr,sizeof(portstr),":%d",ntohs(sin->sin_port));
				strcat(str,portstr);			//��str��ɾ���˿ں�
			}
			return str;			//����ip��ַ
		}
	}

	return NULL;
}