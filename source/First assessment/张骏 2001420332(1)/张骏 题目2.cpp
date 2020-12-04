
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
	int a = 0;	while(a<num1){
		printf("%d\t",c[a]);
		a++;
	}

    a = 0;
	while(a<num2){
		printf("%d\t",d[a]);
		a++;
	}
}

void unRepeat(int c[],int num1,int d[],int num2){//每个参数的意思（数组一，数组一的长度，数组二，数组二的长度）30
	int x[15],e,j,k;
	for(e=0;e<num1;e++)
		x[e]=c[e];
	for(e=0;e<num2;e++)
		x[e+num1]=d[e];
    for(j=0;j<num1+num2-1;j++)
	  for(k=0;k<num1+num2-1-j;k++)
	    if(x[k]>x[k+1])
		{e=x[k];x[k]=x[k+1];x[k+1]=e;}
    for(e=0;e<=num1+num2;e++)//40
	 if(x[e]!=x[e+1]) printf("%d\t",x[e]);
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