#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//���ȥ������

int getRands(int Ints[]) {
	int i = 0;
	int num = rand() % 10 + 1;
	for (; i < num; i++) {
		Ints[i] = rand() % 10;
		printf("%d\t", Ints[i]);
	}
	printf("the end\n");
	return num;
}
void printfun(int c[], int num1, int d[], int num2) {
	int a = 0;

	while (a < num1) {
		printf("%d\t", c[a]);
		a++;
	}

	a = 0;
	while (a < num2) {
		printf("%d\t", d[a]);
		a++;
	}
}

void unRepeat(int c[], int num1, int d[], int num2) {//ÿ����������˼������һ������һ�ĳ��ȣ��������������ĳ��ȣ�
	int e[20] = { 0 }, i, j = num1, num = num1 + num2;
		for (i = 0; i < num1; i++)
			e[i] = c[i];
		for (i = 0; i < num2; i++, j++)
			e[j] = d[i];//����

		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				if (e[i] == e[j])
				{
					for (int k = j + 1; k < num; k++)
						e[k - 1] = e[k];
					num--; j--;
				}
			}
		}//ȥ��

		int temp;
		for (i = 0; i < num - 1; i++)
		{
			for (j = 0; j < num - 1 - i; j++)
				if (e[j] > e[j + 1])
				{
					temp = e[j]; e[j] = e[j + 1]; e[j + 1] = temp;
				}
		}//����

		for (i = 0; i < num; i++)
			printf("%d\t", e[i]);//���
}
int main() {
	srand((unsigned)time(NULL));
	int i = 0;
	int c[10];
	int d[10];
	printf("������ɵĵ�һ�����飺\n");
	int num1 = getRands(c);
	printf("������ɵĵڶ�������: \n");
	int num2 = getRands(d);
	printf("����֮ǰ��\n");
	printfun(c, num1, d, num2);
	printf("\n");
	printf("����֮��\n");
	unRepeat(c, num1, d, num2);
	return 0;
}
