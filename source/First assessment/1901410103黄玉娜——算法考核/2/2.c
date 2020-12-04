#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//组合去重排序

int getRands(int Ints[])
{
    int i = 0;
    int num = rand()%10+1;
    for(; i<num; i++)
	{
        Ints[i]=rand()%10;
        printf("%d\t",Ints[i]);
    }
    printf("the end\n");
    return num;
}
void printfun(int c[],int num1,int d[],int num2)
{
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

void unRepeat(int c[],int num1,int d[],int num2) 
{
    //每个参数的意思（数组一，数组一的长度，数组二，数组二的长度）
    int s[20] = {0};
    int i,j,t,a;
	int k=0;
    for(i=0; i<num1; i++)
    {
        s[k]=c[i];
        k++;
    }

    for(j=0; j<num2; j++)
    {
        s[k] = d[j];
        k++;
    }
  
  
    for(i=0; i<num1+num2; i++)
    {
        for(j=i+1; j<k; j++)
        {
			if(s[i]>s[j])
            {
				t = s[i];
                s[i] = s[j];
                s[j] = t;
            }
        }
    }
    for(i=0;i<(k-1);++i)
    {
		for(j=i+1;j<k;++j)
        {
			if(s[i]==s[j])
            {
                for(a=j;a<(k-1);++a)
                {
					s[a] = s[a+1];
				}
                --k;
    		    --j;
			}
		}
	}
 
    for(i=0; i<k; i++)
    {
        printf("%d\t",s[i]);
    }
	printf("\n");
}
int main()
{
 
    int i = 0;
    int c[10];
    int d[10];
	int num1;
	int num2;
    srand((unsigned)time(NULL));
    printf("随机生成的第一组数组：\n");
    num1=getRands(c);
    printf("随机生成的第二组数组: \n");
    num2=getRands(d);
    printf("处理之前：\n");
    printfun(c,num1,d,num2);
    printf("\n");
    printf("处理之后：\n");
    unRepeat(c,num1,d,num2);
    return 0;
}