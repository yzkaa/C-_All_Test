#include<stdio.h>
void main()
{
	char a[20],b[20],i,n1,n2;
	printf("�����һ���ַ���");
		gets(a);
	printf("����ڶ����ַ���");
		gets(b);
	for(i=0;a[i]!=0;i++)
		n1=i;
	for(i=0;b[i]!=0;i++)
		n2=i;
	if (n1>n2)
		printf("����ϳ����ַ���:%s\n",a);
	if (n1<n2)
		printf("����ϳ����ַ���:%s\n",b);
}