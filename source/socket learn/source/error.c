#include<stdlib.h>
#include<stdio.h>
#include"error.h"
void err_sys(const char * str) 
{ 
    fprintf(stderr,"%s\n",str); 
    exit(1); 
}