#include<stdio.h>
int main()
{
	char a,b;
	int la=0,lb=0,ans=0;
	printf("分别输入两个字符串:\n");
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
	printf("最长为%d个字符",ans);
} 
