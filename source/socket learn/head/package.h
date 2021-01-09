#include<sys/socket.h>
int Socket(int family,int type,int protocol);
void Bind(int fd,const struct sockaddr *sa,socklen_t len);
void Listen(int fd,int backlog);
int Accept(int fd,const struct sockaddr *sa,socklen_t *salenptr);
void Write(int fd, void *ptr, size_t nbytes);
void Close(int fd);