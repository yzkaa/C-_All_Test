#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//���ȥ������

int getRands(int Ints[])
{
	int i =0;
	int num = rand()%10+1;
	for(;i<num;i++)
	{
		Ints[i]=rand()%10;
		printf("%d\t",Ints[i]);
	}
	printf("the end\n");
	return num;
}
void printfun(int c[],int num1,int d[],int num2){
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

void unRepeat(int c[20],int num1,int d[20],int num2)
{
	//ÿ����������˼������һ������һ�ĳ��ȣ��������������ĳ��ȣ�
	int i=0,j=0,k=0,m[20];
	while (i<num1)
	{
		m[k++] = c[i++];//��һ���鵼��m
}
	while (j<num2)
	{
		m[k++] = d[j++];//�������鵼��m
}
	printf("\nc����Ϊ:");
	for (i=0;i<20; i++)
	{
		printf("%d",c[i]);
}
	//��m�����С��������
	for (i=0;i<20 -1; i++)
	{
		for (j=0; j<20-1-i; j++)
		{
			if (c[j] > c[j + 1])
		{
				int temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
		}
		}
	}
	printf("\n�ϲ�������m����Ϊ:");//�������
	for (i=0;i<20; i++)
	{
	printf("%d",c[i]);
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
