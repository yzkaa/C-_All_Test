#include<stdio.h>

int str(char *x)
{
	if(*x++ =='\0') return 0;
	else return ("%d",1+str(x++));
}

int main()
{
	int  line1=0,line2=0;
	char c,a[10000],b[10000];
	scanf("%s",a);
	scanf("%s",b);
	line1=str(a);
	line2=str(b);
	if(line1>=line2)
	printf("最长为%d个字符",line1);
	else
	printf("最长为%d个字符",line2);
	return 0;
}