#include<stdio.h>
 int main()
{
char a[20],b[20];
int i,n1=0,n2=0;
printf("�������һ���ַ�����");
gets(a);
printf("������ڶ����ַ�����");
gets(b);
for(i=0;a[i]!='\0';i++)
n1=i+1;
for(i=0;b[i]!='\0';i++)
n2=i+1;
if(n1>=n2)
printf("����ַ������ǣ�%d\n",n1);
if(n1<n2)
printf("����ַ������ǣ�%d\n",n2);
    return 0;
}