#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//���ȥ������

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

void unRepeat(int c[],int num1,int d[],int num2)//ÿ����������˼������һ������һ�ĳ��ȣ��������������ĳ��ȣ�
{	
    int a,n,b[20];
	a=-1;
    for(;a<num1;a++)
	{b[a]=c[a];}
	n=a,a=0;
	for(;a<num2;a++)
	{b[n]=d[a],n++;}                 //����������ϲ���һ�����飬�������.
	int s=num1+num2,r,p,g[20],k;
		for(a=0,k=0,p=0;a<s;a++)
		{r=a+1,p=0;
			do {if(b[a]==b[r]) p++;
				r++;}while(r<s);
			if(p==0) g[k]=b[a],k++;}//�������.
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
	printf("������ɵĵ�һ�����飺\n");
	int num1=getRands(c);
	printf("������ɵĵڶ�������: \n");
	int num2=getRands(d);
    printf("����֮ǰ��\n");
	printfun(c,num1,d,num2);
	printf("\n");
	printf("����֮��\n");
	unRepeat(c,num1,d,num2);
	return 0;
}