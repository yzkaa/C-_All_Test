#include <stdio.h>
int main()
{
	float insert(float c[3][3]);//�������뺯��
	float check(float c[3][3]);//�������Һ���
	float matrix[3][3];
	insert(matrix);
	printf("\n");
	check(matrix);
	printf("\n");
	printf("�������\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%4.2f\t", matrix[i][j]);
		printf("\n");
	}

	return 0;
}

float insert(float c[3][3])//�������뺯��
{
	printf("��������Ԫ�أ�");
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			scanf("%f", &c[i][j]);
		}
}

float check(float c[3][3])//������Һ���
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (c[i][j] - 3.14 <= 1e-6 && c[i][j] - 3.14 > 0)
			{
				printf("����3.14��ֵ�кţ�%d, �к�:%d\n", i + 1, j + 1);
			}
	}
}
