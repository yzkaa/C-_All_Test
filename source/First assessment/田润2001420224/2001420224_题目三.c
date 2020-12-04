#include<stdio.h>
float P=3.14;
void insert(float matrix[3][3],int i,int j)
{
	scanf("%f",&matrix[i][j]);
}
void check(float matrix[3][3],int i,int j)
{
	if(matrix[i][j]==P)
		printf("等于3.14的值行号:%d,列号:%d\n",i+1,j+1);
}
int main()
{
	float matrix[3][3]={0};
	int i,j;
	printf("请键入插入元素:");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			insert(matrix,i,j);
	printf("\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			check(matrix,i,j);
	printf("\n输出矩阵:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%4.2f\t",matrix[i][j]);
		printf("\n");
	}
	return 0;
} 
