#include<stdio.h>
#include <stdlib.h>
#include <time.h>


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
{int array[20];
int a=0,b=0,t=0;
for(a=0;a<num1;a++)array[a]=c[a];
for(b=0;b<num2;b++)array[num1+b]=d[b];
for(b=0;b<num1+num2-1;b++)
for(a=0;a<num1+num2-1;a++)
{
if(array[a]>array[a+1])
{
t=array[a];array[a]=array[a+1];array[a+1]=t;
}
}
for(a=0;a<num1+num2;a++)
{if(array[a]!=array[a+1])
printf("%d\t",array[a]);
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