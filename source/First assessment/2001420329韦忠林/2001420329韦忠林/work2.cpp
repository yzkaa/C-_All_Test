#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//组合去重排序

int getRands(int Ints[])
{
	int i =0;
	int num = rand()%10+1;
	for(;i<num;i++)
	{
		Ints[i]=rand()%10;
		printf("%d\t",Ints[i]);
	}
	printf("the end\n");
	return num;
}
void printfun(int c[],int num1,int d[],int num2){
int a = 0;
	
	while(a<num1)
	{
		printf("%d\t",c[a]);
		a++;
	}

    a = 0;
	while(a<num2)
	{
		printf("%d\t",d[a]);
		a++;
	}

}

void unRepeat(int c[20],int num1,int d[20],int num2)
{
	//每个参数的意思（数组一，数组一的长度，数组二，数组二的长度）
	int i=0,j=0,k=0,m[20];
	while (i<num1)
	{
		m[k++] = c[i++];//将一数组导入m
}
	while (j<num2)
	{
		m[k++] = d[j++];//将二数组导入m
}
	printf("\nc数组为:");
	for (i=0;i<20; i++)
	{
		printf("%d",c[i]);
}
	//将m数组从小到大排序
	for (i=0;i<20 -1; i++)
	{
		for (j=0; j<20-1-i; j++)
		{
			if (c[j] > c[j + 1])
		{
				int temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
		}
		}
	}
	printf("\n合并排序后的m数组为:");//输出数组
	for (i=0;i<20; i++)
	{
	printf("%d",c[i]);
	}








}
int main()
{
	srand((unsigned)time(NULL));
	int i=0;
	int c[10];
	int d[10];
	printf("随机生成的第一组数组：\n");
	int num1=getRands(c);
	printf("随机生成的第二组数组: \n");
	int num2=getRands(d);
    printf("处理之前：\n");
printfun(c,num1,d,num2);
	printf("\n");
	printf("处理之后：\n");
	unRepeat(c,num1,d,num2);
	return 0;
}
