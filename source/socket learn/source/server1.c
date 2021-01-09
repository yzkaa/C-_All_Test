#include<time.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include"package.h"
#define MAXLINE 4096
#define LISTENQ 1024
#define	SA	struct sockaddr
int main(int argc,char **argv){
    int listenfd,connfd;
    socklen_t len;
    struct sockaddr_in servaddr,cliaddr;
    char buff[MAXLINE];
    time_t ticks;
    listenfd = Socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5000);

    Bind(listenfd,(SA*)&servaddr,sizeof(servaddr));
    
    Listen(listenfd,LISTENQ);

    for(;;){
        len = sizeof(cliaddr);
        connfd = Accept(listenfd,(SA *)&servaddr,len);
        printf("connection from %s, port %d\n",
        inet_ntop(AF_INET,&cliaddr,buff,sizeof(buff)),
        ntohs(cliaddr.sin_port));
        ticks = time(NULL);
        snprintf(buff,sizeof(buff),"%.24s\r\n",ctime(ticks));
        Write(connfd,buff,strlen(buff));

        Close(connfd);
    }
    return 0;
}