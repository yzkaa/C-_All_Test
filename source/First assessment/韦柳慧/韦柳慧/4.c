#include<stdio.h>
int main()
{
    int t,n;//定义列程数和窗户数的变量
    int a,b,c;
    int i,j;//定义循环变量
    printf("请输入列程数:");
    scanf("%d",&i);
    for(t=1;t<=i;t++)
{
    j=0;
    printf("请输入窗户数:\n");
    scanf("%d",&n);
    for(a=0;a<n;a++){
        for(b=0;b<n;b++){
            for(c=0;c<n;c++)
            if(n==a*4+b*5+c*7)
            {printf("%d\t%d\t%d\n",a,b,c);
             j=1;}
            if(j==1)break;}
            if(j==1)break;}
    if(a==n)printf("-1\n");
}
    return 0;
}
