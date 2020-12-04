#include<stdio.h>
int main()
{
    char a[5];
    char b[5];
    int n1,n2;
    int i=0;
    printf("请输入第一个字符串: ");
    gets(a);
    printf("请输入第二个字符串: ");
    gets(b);
    for(i=0; a[i]!=0; i++)
        n1=i;
    for(i=0; b[i]!=0; i++)
        n2=i;
    if(n1>n2)
        printf("较长的字符串是: %s\n",a);
    if(n1<n2)
        printf("较长的字符串是: %s\n",b);
    return 0;
}