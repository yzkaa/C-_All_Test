#include<stdio.h>
int main()
{   

	int a,b,c=0,d=0;
	printf("�����������ַ���");
	while((a=getchar())!='\n')c++;
	while((b=getchar())!='\n')d++;
	if(c>d) printf("����ַ�������Ϊ%d",c);
	else printf("����ַ�������Ϊ%d",d);

	return 0;
}
