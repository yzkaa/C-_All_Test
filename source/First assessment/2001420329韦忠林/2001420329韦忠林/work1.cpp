#include<stdio.h>
int main()
{	char a[20],b[20]; int n1,n2,i;
	printf("�������һ���ַ�����"); 
	gets(a);
	printf("������ڶ����ַ�����"); 
	gets(b);
	for(i=0;a[i]!=0;i=i+1)//*ͳ�Ƶ�һ���ַ����ĳ���*//
	n1=i+1;
	for(i=0;b[i]!=0;i=i+1)//*ͳ�Ƶڶ����ַ����ĳ���*//
	n2=i+1;
	if(n1>n2)
		printf("�ϳ����ַ�������Ϊ��%d\n",n1);
	else
		printf("�ϳ����ַ�������Ϊ��%d\n",n2); 
	
	return 0;
}
