#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//组合去重排序

int getRands(int Ints[]){
	int i =0;
	int num = rand()%10+1;
	for
	(;i<num;i++){
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

void unRepeat(int c[],int num1,int d[],int num2)//每个参数的意思（数组一，数组一的长度，数组二，数组二的长度）
{	
    int a,n,b[20];
	a=-1;
    for(;a<num1;a++)
	{b[a]=c[a];}
	n=a,a=0;
	for(;a<num2;a++)
	{b[n]=d[a],n++;}                 //把两个数组合并成一个数组，方便除亢.
	int s=num1+num2,r,p,g[20],k;
		for(a=0,k=0,p=0;a<s;a++)
		{r=a+1,p=0;
			do {if(b[a]==b[r]) p++;
				r++;}while(r<s);
			if(p==0) g[k]=b[a],k++;}//数组除亢.
	int f[20];
	for(a=0,p=0;a<10;a++)
	{   r=0,p=0;
	if(g[a]>=0)
	{do{if((g[a]>g[r])&&(g[r]>=0)) p++;
		r++;}while(r<20);
		f[p]=g[a];}}
    a = 0;
	while(a<20){
		if(f[a]>=0) printf("%d\t",f[a]);
		a++;
	}
	
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