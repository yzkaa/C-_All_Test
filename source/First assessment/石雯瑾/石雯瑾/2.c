#include<stdio.h>
#include <stdlib.h>
#include <time.h>
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
void unRepeat(int c[],int num1,int d[],int num2){

 	int *temp = NULL,i;
	temp = (int* )malloc(sizeof(int) * num1 + num2);
	
	for( i = 0; i < num1; i++)
	{
		temp[i] = c[i];
	}
	
	for( i = 0; i < num2; i++)
	{
		temp[num1 + i] = d[i];
	}
	int n = num1 + num2;
	for(i = 0; i < n; i++)
	{
		printf("%d\t", temp[i]);
	}
	

	for( i=0;i<n;i++)
	{
		int k = temp[i];
		for(int j=i+1;j<n;j++)
		{

			if(k==temp[j])
			{
				for(int k=j;k<n-1;k++)
				{
					temp[k] = temp[k+1];
				} 
				n--;
				j--;
			}

		}
	}

int aa[20];
for ( i=0;i<n;i++) {
aa[i]=temp[i];
}


int t = 0;
	
	for (i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if(temp[j] < temp[i])
			{
				t = temp[i];
				temp[i] = temp[j];
				temp[j] = t;
			}
		}}




	printf("\n-------------------\n");
	for( i = 0; i < n; i++)
	{
		printf("%d\t", temp[i]);
	}
	free(temp);
	temp = NULL;


	

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