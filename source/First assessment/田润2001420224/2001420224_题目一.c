#include<stdio.h>
int main()
{
	char a,b;
	int la=0,lb=0,ans=0;
	printf("�ֱ����������ַ���:\n");
	while((a=getchar())!='\n')
	{
		la++;
	}
	while((b=getchar())!='\n')
	{
		lb++;
	}
	if(la>lb)
		ans=la;
	else ans=lb;
	printf("�Ϊ%d���ַ�",ans);
} 
