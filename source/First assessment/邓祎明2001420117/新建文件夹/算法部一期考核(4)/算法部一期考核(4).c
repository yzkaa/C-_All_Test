#include <stdio.h>
int main()
{
	int windows(int a);//声明计算并输出的函数
	int n, t;
	printf("请输入例程数量：");
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("请输入窗户数量：");
		scanf("%d", &n);
		windows(n);
	}
	return 0;
}

int windows(int a)//定义计算并输出的函数
{
	int n4, n5, n7;
	for(n4=0;n4<=250;n4++)
		for(n5=0;n5<=200;n5++)
			for (n7 = 0; n7 <= 142; n7++)
			{
				if (4 * n4 + 5 * n5 + 7 * n7 == a)
				{
					printf("%d %d %d\n", n4, n5, n7);
					return;
				}
				if (n4 == 250 && n5 == 200 && n7 == 142)
					printf("-1\n");
			}
}
