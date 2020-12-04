#include<stdio.h>
void main()
{
	int a=-1,b=-1,c=-1,n;
	printf("请输入窗户数量n=");
		scanf("%d",&n);
		for(a=-1;(a*4+b*5+c*7!=n) && a<100;)
		{a++;
		for(b=-1;(a*4+b*5+c*7!=n) && b<100;)
		{b++;
		for(c=0;(a*4+b*5+c*7!=n) && c<100;)
		{c++;}}}
    if(a*4+b*5+c*7==n) 
		printf("%d\n%d\n%d\n",a,b,c);
	else 
		printf("-1");
}