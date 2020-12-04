#include<stdio.h>
int main()
{char c1[100],c2[100];
int d1,d2,i;
char g1,g2;
gets(c1);
gets(c2);
for(d1=0,i=0;(g1=c1[i])!='\0';i++)
{d1++;}
for(d2=0,i=0;(g2=c2[i])!='\0';i++)
{d2++;}
if(d1>d2) printf("%d\n",d1);
else printf("%d\n",d2);
return 0;}