#include<stdio.h>
 int main()
{
char a[20],b[20];
int i,n1=0,n2=0;
printf("请输入第一个字符串：");
gets(a);
printf("请输入第二个字符串：");
gets(b);
for(i=0;a[i]!='\0';i++)
n1=i+1;
for(i=0;b[i]!='\0';i++)
n2=i+1;
if(n1>=n2)
printf("最长的字符个数是：%d\n",n1);
if(n1<n2)
printf("最长的字符个数是：%d\n",n2);
    return 0;
}