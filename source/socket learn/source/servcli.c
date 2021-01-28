#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SERV_PORT 1024
#define MAXLINE 4096
int main(int argc,char **argv){
    int sockfd;
    struct sockaddr_in servaddr;
    if(argc !=2){
        printf("usage:tcpcli <ipaddress>");
        return 0;
    }
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    str_cli(stdin,sockfd);
    exit(0);
}

void str_cli(FILE *fp,int sockfd){
    char sendline[MAXLINE],recvline[MAXLINE];
    while(fgets(sendline,MAXLINE,fp)!=NULL){
        write(sockfd.recvline,MAXLINE);
        if(readline(sockfd,sendline,strlen(sendline))==0){
            printf("server terminated prematurely");
        }
        fputs(recvline,stdout);
    }
}
