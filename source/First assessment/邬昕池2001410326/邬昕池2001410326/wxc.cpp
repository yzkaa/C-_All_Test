#include<stdio.h>
void main()
{
	char a[20],b[20],i,n1,n2;
	printf("输入第一组字符串");
		gets(a);
	printf("输出第二组字符串");
		gets(b);
	for(i=0;a[i]!=0;i++)
		n1=i;
	for(i=0;b[i]!=0;i++)
		n2=i;
	if (n1>n2)
		printf("输出较长的字符串:%s\n",a);
	if (n1<n2)
		printf("输出较长的字符串:%s\n",b);
}