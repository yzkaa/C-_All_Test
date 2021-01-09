#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
// ssize_t readn(int fd, void *vptr, size_t n){
//     size_t nleft;       //sockfd中剩余的字符,fd = file descriptor
//     size_t nread;       //读取的字节
//     char *ptr;          //读取位置的指针

//     ptr = vptr;
//     nleft = n;
//     while(nleft>0){     //当字节还有剩余
//         if((nread = read(fd,ptr,nleft))<0){     //如果read错误，判断是程序中断还是其他原因     
//             if(errno == EINTR){                 //如果进程在一个慢系统调用中阻塞时，nread设置为0
//                 nread = 0;
//             }
//             else{                               //若为其他原因，返回-1；
//                 return -1;
//             }
//         }
//         else if (nread == 0){                   //等于0代表读取完毕，跳出循环
//             break;
//         }

//         nleft -= nread;                         //从剩余字节中减掉读取的字节
//         ptr +=nread;                            //将指针向后移动至读取的字节之后
//     }
//     return (n-nleft);                           //返回最终读取的字节数
// }

// ssize_t writen(int fd,const void *vptr,size_t n){
//     size_t nleft;       //剩余字节
//     ssize_t nwritten;   //写入的字节
//     const char *ptr;    //位置指针

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
//         if((rc = read(fd,&c,1)) == 1){  //如果成功读取，进入循环
//             *ptr++ = c;
//             if(c == '\n'){              //遇到换行符终止循环
//                 break;
//             }
//             else if(rc == 0){           //如果读取结束并没有遇到换行符，返回读取的所有字节的个数。
//                 *ptr = 0;
//                 return n-1;             
//             }
//             else{
//                 if(errno == EINTR){     //如果中断，尝试重新读取
//                     n--;
//                     continue;
//                 }
//                 return -1;
//             }
//         }
//     }
//     *ptr = 0;
//     return n;                           //返回最终读取的字节数
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
//         if((rc = my_read(fd,&c)) == 1){  //如果成功读取，进入循环
//             *ptr++ = c;
//             if(c == '\n'){              //遇到换行符终止循环
//                 break;
//             }
//             else if(rc == 0){           //如果读取结束并没有遇到换行符，返回读取的所有字节的个数。
//                 *ptr = 0;
//                 return n-1;             
//             }
//             else{
//                 if(errno == EINTR){     //如果中断，尝试重新读取
//                     n--;
//                     continue;
//                 }
//                 return -1;
//             }
//         }
//     }
//     *ptr = 0;
//     return n;                           //返回最终读取的字节数
// }

// ssize_t readlinebuf(void **vptrptr){
//     if(read_cnt){
//         *vptrptr = read_ptr;
//     }
//     return read_cnt;
// }


int inet_pton_loose(int family, const char *strptr, void *addrptr){
	if(family == AF_INET){			//支持ipv4
		struct in_addr in_val;		//存放地址
        int a;
        if((a=inet_pton(family,strptr,addrptr)) ==0){
            printf("inet_pton failed");
            if(inet_aton(strptr,&in_val)){		//如果返回值为1，即字符串有效，将ASCII转换为二进制ipv4地址
			    memcpy(addrptr , &in_val,sizeof(struct in_addr));	//将转换值复制到addrptr所指向的空间中
			    return 1;						//返回1
		    }
		    return 0;							//如果字符串无效，返回0
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
