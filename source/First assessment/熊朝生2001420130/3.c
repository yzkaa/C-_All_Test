#include<stdio.h>
float matrix[3][3];
int main()
{
void insert(),check();
int i=0,j=0;
insert();
check();
printf("�������:");
for(;i<3;i++)
{printf("\n");
for(j=0;j<3;j++)
printf("%4.2f\t",matrix[i][j]);}
}

void insert()
{
int i=0,j=0;
printf("��������Ԫ��:");
for(;i<3;i++)
for(j=0;j<3;j++)
scanf("%f",&matrix[i][j]);//��������Ԫ��
}

void check()
{
int i=0,j=0,k=0;
for(;i<3;i++)
for(j=0;j<3;j++)
{k=(int)(matrix[i][j]*100);
if(k==314)//�ж�Ԫ�ص�ֵ�Ƿ�Ϊ3.14
printf("����3.14���к�:%d,�к�:%d\n",i+1,j+1);}
}
    
