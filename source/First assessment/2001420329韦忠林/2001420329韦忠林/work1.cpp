#include<stdio.h>
int main()
{	char a[20],b[20]; int n1,n2,i;
	printf("请输入第一个字符串："); 
	gets(a);
	printf("请输入第二个字符串："); 
	gets(b);
	for(i=0;a[i]!=0;i=i+1)//*统计第一个字符串的长度*//
	n1=i+1;
	for(i=0;b[i]!=0;i=i+1)//*统计第二个字符串的长度*//
	n2=i+1;
	if(n1>n2)
		printf("较长的字符串长度为：%d\n",n1);
	else
		printf("较长的字符串长度为：%d\n",n2); 
	
	return 0;
}
