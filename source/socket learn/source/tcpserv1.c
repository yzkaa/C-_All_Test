#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#define SERV_PORT 6666
#define LISTENQ 1024 
#define MAXLINE 4096
int main(int argc,char **argv)
{
    int listenfd,connfd;
    pid_t childPid;
    socklen_t clilen;
    struct sockaddr_in cliaddr,servaddr;
    listenfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    bind(listenfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    listen(listenfd,LISTENQ);
    while(1){
        clilen = sizeof(cliaddr);
        connfd = accept(listenfd,(struct sockaddr *)&cliaddr,&clilen);
        if((childPid = fork())==0){
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd);
    }
    return 0;
}
void str_echo(int sockfd){
    ssize_t n;
    char buf[MAXLINE];
again:
    while((n=read(sockfd,buf,MAXLINE))>0){
        write(sockfd,buf,n);
    }
    if(n>0 && errno == EINTR){
        goto again;
    }
    else if (n<0){
        printf("read error");
    }
}
