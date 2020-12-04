#include <stdio.h>
int main()
{
	float insert(float c[3][3]);//声明输入函数
	float check(float c[3][3]);//声明查找函数
	float matrix[3][3];
	insert(matrix);
	printf("\n");
	check(matrix);
	printf("\n");
	printf("输出矩阵\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%4.2f\t", matrix[i][j]);
		printf("\n");
	}

	return 0;
}

float insert(float c[3][3])//定义输入函数
{
	printf("请键入插入元素：");
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			scanf("%f", &c[i][j]);
		}
}

float check(float c[3][3])//定义查找函数
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (c[i][j] - 3.14 <= 1e-6 && c[i][j] - 3.14 > 0)
			{
				printf("等于3.14的值行号：%d, 列号:%d\n", i + 1, j + 1);
			}
	}
}
