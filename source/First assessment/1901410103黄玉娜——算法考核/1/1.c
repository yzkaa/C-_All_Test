#include<stdio.h>
void main()
{
	int i=0;
	int n=0;
	int j=0;
	int m=0;
	char str1[10000];
	char str2[10000];
	printf("�ֱ����������ַ�����\n");
	scanf("%s",&str1);
	scanf("%s",&str2);

	for(i=0;str1[i]!='\0';i++)
	{
		n=i+1;
	}
	for(j=0;str2[j]!='\0';j++)
	{
		m=j+1;
	}
	if(n>=m)
		printf("�Ϊ%d���ַ�\n", n);
	else
		printf("�Ϊ%d���ַ�\n", m);
}
		
