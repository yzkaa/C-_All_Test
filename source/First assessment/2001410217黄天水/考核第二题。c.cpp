#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//���ȥ������

int getRands(int Ints[]){
	int i =0;
	int num = rand()%10+1;//1~10���ȡֵ�����鳤��
	for(;i<num;i++){
		Ints[i]=rand()%10;//�������ȡ��
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

void unRepeat(int c[],int num1,int d[],int num2){//ÿ����������˼������һ������һ�ĳ��ȣ��������������ĳ��ȣ�
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
//����
	s=l-1;
    for(j=0;j<l-1;j++)
	{
	   if(g[j]==g[j+1]) 
			  continue;
	      printf("%d\t",g[j]);
	}
    printf("%d\n",g[s]);
	//ȥ�ظ�	
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
