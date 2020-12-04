#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//组合去重排序

int getRands(int Ints[]){
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

void unRepeat(int c[],int num1,int d[],int num2);
int main(){
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
void unRepeat(int c[],int num1,int d[],int num2)
{   int a[100];
	int i=0,j=0,k=0,t,a[num1+num2];
	while(i<num1)
	{
		a[k]=c[i];
		k++;
		i++;
	}
	i=0;
	while(i<num2)
	{
		a[k]=d[i];
		k++;
		i++;
	}
	for(i=1;i<num1+num2;i++)
	{
		for(j=0;j<(num1+num2)-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;	
			}
		}
	}
	for(i=0;i<num1+num2;i++)
	{
		if(a[i]!=a[i+1])
		printf("%d\t",a[i]);
	}
}