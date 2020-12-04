#include<stdio.h>
#include<math.h>
int main()
{
    int i,j;
	float matrix[3][3];
	const double eps=1E-6;
	printf("请输入元素：");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%f",&matrix[i][j]);
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(fabs(matrix[i][j]-3.14)<=eps)
			printf("等于3.14的值行号：%d，列号：%d\n",i,j);
		}
	}
		printf("输出矩阵:\n");
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		    printf("%.2f\t",matrix[i][j]);
		}
		printf("\n");
	}
    return 0;
}
