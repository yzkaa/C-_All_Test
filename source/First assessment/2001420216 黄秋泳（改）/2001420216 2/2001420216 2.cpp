#include<stdio.h>
#include <stdlib.h>
#include <time.h>
													//���ȥ������

int getRands(int Ints[])
{
    int i =0;
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
{													//ÿ����������˼������һ������һ�ĳ��ȣ��������������ĳ��ȣ�
    int a = 0,i,j,m,n,x=0,y,z;
    int g[10];										//��ʹc[10]��b[10]���ڷֱ�Ϊ��ͬ����������10��Ԫ�ض�����ֵ��c[10]��b[10]��ֻ��Ϊ{0,1,2,3,4,5,6,7,8,9,}
    int f [20] ;
    for(i = 0;i < num1;i++)
    {
        f[a++] = c[i];
    }
    
    for(j = 0;j < num2;j++)
	   {
        f[a++] = d[j];
    }
	   for(m = 0;m<a;m++)
    {
        for(n = 0;n<m;n++)
        {
            if(f[m]==f[n])
                f[m] = 10;
        }
    }
    for(m = 0;m<a;m++)
    {
        if(f[m]!=10)								//ͨ�������ڵ���������ȥ�ظ������ݣ�����ɸѡ������ݸ�ֵ����һ������
		{
            g[x++]=f[m];
        }
    }
    for(z = 0;z<10;z++)
    {
        for(y = 0;y<x;y++)
        {
            if(z==g[y])
            printf("%-8d",z);
        }
    }
}

int main()
{
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