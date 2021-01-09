#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
// ssize_t readn(int fd, void *vptr, size_t n){
//     size_t nleft;       //sockfd��ʣ����ַ�,fd = file descriptor
//     size_t nread;       //��ȡ���ֽ�
//     char *ptr;          //��ȡλ�õ�ָ��

//     ptr = vptr;
//     nleft = n;
//     while(nleft>0){     //���ֽڻ���ʣ��
//         if((nread = read(fd,ptr,nleft))<0){     //���read�����ж��ǳ����жϻ�������ԭ��     
//             if(errno == EINTR){                 //���������һ����ϵͳ����������ʱ��nread����Ϊ0
//                 nread = 0;
//             }
//             else{                               //��Ϊ����ԭ�򣬷���-1��
//                 return -1;
//             }
//         }
//         else if (nread == 0){                   //����0�����ȡ��ϣ�����ѭ��
//             break;
//         }

//         nleft -= nread;                         //��ʣ���ֽ��м�����ȡ���ֽ�
//         ptr +=nread;                            //��ָ������ƶ�����ȡ���ֽ�֮��
//     }
//     return (n-nleft);                           //�������ն�ȡ���ֽ���
// }

// ssize_t writen(int fd,const void *vptr,size_t n){
//     size_t nleft;       //ʣ���ֽ�
//     ssize_t nwritten;   //д����ֽ�
//     const char *ptr;    //λ��ָ��

//     ptr = vptr;
//     nleft =n;
//     while(nleft >0){
//         if((nwritten = write(fd,ptr,nleft)) <= 0){
//             if(nwritten <0 && errno == EINTR){
//                 nwritten = 0;
//             }
//             else{
//                 return -1;
//             }
//         }

//         nleft -= nwritten;
//         ptr += nwritten;
//     }
//     return n;
//}

// ssize_t readline(int fd,void *vptr,size_t maxlen){
//     ssize_t n,rc;
//     char c,*ptr;

//     ptr = vptr;
//     for(n=1;n<maxlen;n++){
//         if((rc = read(fd,&c,1)) == 1){  //����ɹ���ȡ������ѭ��
//             *ptr++ = c;
//             if(c == '\n'){              //�������з���ֹѭ��
//                 break;
//             }
//             else if(rc == 0){           //�����ȡ������û���������з������ض�ȡ�������ֽڵĸ�����
//                 *ptr = 0;
//                 return n-1;             
//             }
//             else{
//                 if(errno == EINTR){     //����жϣ��������¶�ȡ
//                     n--;
//                     continue;
//                 }
//                 return -1;
//             }
//         }
//     }
//     *ptr = 0;
//     return n;                           //�������ն�ȡ���ֽ���
// }

// #define MAXLINE 4096
// static int read_cnt;
// static char *read_ptr;
// static char read_buf[MAXLINE];

// static ssize_t my_read(int fd, char *ptr){
//     if(read_cnt <= 0){
//     again:
//         if((read_cnt = read(fd,read_buf,sizeof(read_buf)))<0){
//             if(errno == EINTR){
//                 goto again;
//             }
//             return -1;
//         }else if(read_cnt == 0){
//             return 0;
//         }
//         read_ptr = read_buf;
//     }
//     read_cnt--;
//     *ptr = *read_ptr++;
//     return 1;
// }

// ssize_t readline(int fd,void *vptr,size_t maxlen){
//     ssize_t n,rc;
//     char c,*ptr;

//     ptr = vptr;
//     for(n=1;n<maxlen;n++){
//         if((rc = my_read(fd,&c)) == 1){  //����ɹ���ȡ������ѭ��
//             *ptr++ = c;
//             if(c == '\n'){              //�������з���ֹѭ��
//                 break;
//             }
//             else if(rc == 0){           //�����ȡ������û���������з������ض�ȡ�������ֽڵĸ�����
//                 *ptr = 0;
//                 return n-1;             
//             }
//             else{
//                 if(errno == EINTR){     //����жϣ��������¶�ȡ
//                     n--;
//                     continue;
//                 }
//                 return -1;
//             }
//         }
//     }
//     *ptr = 0;
//     return n;                           //�������ն�ȡ���ֽ���
// }

// ssize_t readlinebuf(void **vptrptr){
//     if(read_cnt){
//         *vptrptr = read_ptr;
//     }
//     return read_cnt;
// }


int inet_pton_loose(int family, const char *strptr, void *addrptr){
	if(family == AF_INET){			//֧��ipv4
		struct in_addr in_val;		//��ŵ�ַ
        int a;
        if((a=inet_pton(family,strptr,addrptr)) ==0){
            printf("inet_pton failed");
            if(inet_aton(strptr,&in_val)){		//�������ֵΪ1�����ַ�����Ч����ASCIIת��Ϊ������ipv4��ַ
			    memcpy(addrptr , &in_val,sizeof(struct in_addr));	//��ת��ֵ���Ƶ�addrptr��ָ��Ŀռ���
			    return 1;						//����1
		    }
		    return 0;							//����ַ�����Ч������0
        }
        return 1;
	}

    if(family ==AF_INET6){
        struct in_addr in_val;
        int a;
        if((a=inet_pton(family,strptr,addrptr))==0){
            printf("inet_pton failed");
            if(inet_aton(strptr,&in_val)){
                memcpy(addrptr,&in_val,sizeof(struct in_addr));
                return 1;
            }
            return 0;
        }
        return 1;
    }
}

int main(int argc, char **argv){
    if(argc<3){
        printf("input format: ./main <family> <address>\n");
        return 1;
    }
    in_addr_t addr;
    struct sockaddr_in6 addr6;
    addr6.sin6_addr = in6addr_any;
    bzero(&addr, sizeof(addr));

    if(strcmp(argv[1],"AF_INET")==0){
        if(inet_pton_loose(AF_INET,argv[2], (void*)&addr) <=0){
            printf("error");
            return 0;
        }
        printf("IPv4 address: %08x\n ",addr);
        return 1;
    }
    if(strcmp(argv[1],"AF_INET6")==0){
        if(inet_pton_loose(AF_INET6,argv[2], (void*)&addr6.sin6_addr) <=0){
            printf("error");
            return 0;
        }
        printf("IPv6 address:%X\n",addr6.sin6_addr);
        return 1;
    }
    printf("family not support\n");
    return 0;
}
