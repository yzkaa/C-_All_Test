#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//组合去重排序

int getRands(int Ints[]){
	int i =0;
	int num = rand()%10+1;//1~10随机取值，数组长度
	for(;i<num;i++){
		Ints[i]=rand()%10;//数组随机取数
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

void unRepeat(int c[],int num1,int d[],int num2){//每个参数的意思（数组一，数组一的长度，数组二，数组二的长度）
	int j,k,f,g[20],l,s,x;
	for(j=0;j<num1;j++)
	    g[j]=c[j];
	l=num1+num2;
    for(j=num1,k=0;j<l;j++,k++)
			g[j]=d[k];

	for(j=0;j<l;j++)
	{
		for(k=j;k<l;k++)
		{
			if(g[j]>=g[k]) 
			{
			   f=g[j]; 
			   g[j]=g[k]; 
			   g[k]=f;
			}
		}
	}
	for(j=0;j<l;j++)
		printf("%d\t",g[j]);
	printf("\n");
//排序
	s=l-1;
    for(j=0;j<l-1;j++)
	{
	   if(g[j]==g[j+1]) 
			  continue;
	      printf("%d\t",g[j]);
	}
    printf("%d\n",g[s]);
	//去重复	
}
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
