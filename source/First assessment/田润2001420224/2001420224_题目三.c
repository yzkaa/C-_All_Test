#include<stdio.h>
float P=3.14;
void insert(float matrix[3][3],int i,int j)
{
	scanf("%f",&matrix[i][j]);
}
void check(float matrix[3][3],int i,int j)
{
	if(matrix[i][j]==P)
		printf("����3.14��ֵ�к�:%d,�к�:%d\n",i+1,j+1);
}
int main()
{
	float matrix[3][3]={0};
	int i,j;
	printf("��������Ԫ��:");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			insert(matrix,i,j);
	printf("\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			check(matrix,i,j);
	printf("\n�������:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%4.2f\t",matrix[i][j]);
		printf("\n");
	}
	return 0;
} 
