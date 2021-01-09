#include "package.h"
#include "error.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int Socket(int family,int type,int protocol){
    int n = 0;
    if((n=socket(family,type,protocol))<0){
        err_sys("socket error");
    }
    return n;
}

void Bind(int fd,const struct sockaddr *sa,socklen_t len){
    if(bind(fd,sa,len)<0){
        err_sys("bind error");
    }
}
void Listen(int fd,int backlog){
    char *ptr;
    if((ptr=getenv("LISTENQ"))!=NULL){
        backlog = atoi(ptr);
    }
    if(listen(fd,backlog)<0){
        err_sys("listen error");
    }
}
int Accept(int fd,const struct sockaddr *sa,socklen_t *salenptr){
    int n;\
again:
    if((n=accept(fd,&sa,salenptr))<0){
#ifdef  EPROTO
        if(errno ==EPROTO || errno == ECONNABORTED)
#else
        if(errno == ECONNABORTED)
#endif
            goto again;
        else
        err_sys("accept error");
    }
    return n;
}
void Write(int fd ,void *ptr,size_t nbytes ){
    if(write(fd,ptr,nbytes)!=nbytes){
        err_sys("write error");
    }
}
void Close(int fd){
    if(close(fd)==-1){
        err_sys("close error");
    }
}