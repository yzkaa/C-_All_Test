#include<sys/socket.h>
#include<stdlib.h>
#include<stdio.h>
void err_sys(const char * str) 
{ 
    fprintf(stderr,"%s\n",str); 
    exit(1); 
}
void Listen(int fd,int backlog){
    char *ptr;
    if((ptr = getenv("LISTENQ"))!=NULL){
        backlog = atoi(ptr);
    }

    if(listen(fd,backlog) < 0){
        err_sys("listen error");
    }
}