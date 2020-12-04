#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//组合去重排序

int getRands(int Ints[])
{
	int i =0;
	int num = rand()%10+1;
	for(;i<num;i++){
		Ints[i]=rand()%10;
		printf("%d\t",Ints[i]);
	}
	printf("the end\n");
	return num;
}
void printfun(int c[],int num1,int d[],int num2){
	int a = 0;
	
	while(a<num1){
		printf("%d\t",c[a]);
		a++;
	}

    a = 0;
	while(a<num2){
		printf("%d\t",d[a]);
		a++;
	}
}
void unRepeat(int c[],int num1,int d[],int num2)
{//每个参数的意思（数组一，数组一的长度，数组二，数组二的长度）
	int array[20];
	int i=0,j=0,t=0;
	for(i=0;i<num1;i++)array[i]=c[i];
	for(j=0;j<num2;j++)array[num1+j]=d[j];
	for(j=0;j<num1+num2-1;j++)
		for(i=0;i<num1+num2-1-j;i++)
		{
			if (array[i]>array[i+1])
			{t=array[i];array[i]=array[i+1];array[i+1]=t;}
		}
	for(i=0;i<num1+num2;i++)
		{	if(array[i]!=array[i+1])
			printf("%d\t",array[i]);
		}
	printf("\n"); 
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
    printf("处理之前: \n");
	printfun(c,num1,d,num2);
	printf("\n");
	printf("处理之后：\n");
	unRepeat(c,num1,d,num2);
	return 0;
}

