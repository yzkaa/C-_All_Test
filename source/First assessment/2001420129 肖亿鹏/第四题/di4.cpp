#include<stdio.h>
int main()
{
	int a=-1,b=-1,c=-1,n;
	printf("请输入窗户数量n=");
		scanf("%d",&n);
		for(a=-1;(a*4+b*5+c*7!=n) && a<100;){a++;
		for(b=-1;(a*4+b*5+c*7!=n) && b<100;){b++;
		for(c=-1;(a*4+b*5+c*7!=n) && c<100;){c++;}}}
    if(n==1) printf("-1");
		if(n>1&&n<100) 
			printf("%d\n%d\n%d\n",a,b,c);
	return 0;
}
