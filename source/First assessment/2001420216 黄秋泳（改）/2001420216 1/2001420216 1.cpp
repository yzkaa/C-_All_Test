#include <stdio.h>
int main()
{
    int n = 0,m = 0;
    printf("input a string:\n");
    
   while(getchar()!='\n')
    {
         n++;
    }
    while(getchar()!='\n')
    {
         m++;
    }
    if(n > m)
    printf("%d",n);
    else
    printf("%d",m);
}