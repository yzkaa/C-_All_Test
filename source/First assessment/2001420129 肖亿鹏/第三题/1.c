#include<stdio.h>
float matrix[3][3];
int i=0,j=0;
int main()
{
	int insert(),check();
	printf("��������Ԫ��:");
	insert();
	check();
	printf("�������:");
	for(;i<3;i++)
	{printf("\n");
	for(j=0;j<3;j++)
		printf("%4.2f\t",matrix[i][j]);}
}

int insert()
{
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%f",&matrix[i][j]);
		return 0;
}

int check()
{
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(matrix[i][j]<3.15&&matrix[i][j]>3.13)
				printf("����3.14���к�:%d,�к�:%d\n",i+1,j+1);
			return 0;
}
