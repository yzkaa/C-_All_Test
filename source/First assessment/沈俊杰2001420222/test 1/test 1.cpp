#include<stdio.h>
int main()
{   

	int a,b,c=0,d=0;
	printf("请输入两条字符串");
	while((a=getchar())!='\n')c++;
	while((b=getchar())!='\n')d++;
	if(c>d) printf("最长的字符串长度为%d",c);
	else printf("最长的字符串长度为%d",d);

	return 0;
}
