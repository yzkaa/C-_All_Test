#include<stdio.h>
int main()
{
float matrix[3][3] = {0};
	int i = 0; //列
	int j = 0; //行
	float data = 0.f;
	printf("请依次插入九个元素，并用空格隔开:");
	scanf("%f", &data);
	while(j >= 3)
	{
	
		i++;
		if(i >= 3)
		{
			i = 0;
			j++; 
		}
	} 
/*	float check,matrix[3][3]={x};
int i,j
char y
printf("数值为3.14的值是第%d行，第%d列"，j,i)
while(x!=y)
 y++;
if(x==y)*/

}
