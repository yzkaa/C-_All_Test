#include<stdio.h>

int main()
{
    int x,y,z,i,t,n;
    printf("������ѭ������");
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
    printf("�����봰����");
    scanf("%d",&n);{
    if(n==1)
    printf("-1");}
    for(x=0;4*x<=n;x++)
    for(y=0;5*y<=n;y++)
    for(z=0;7*z<=n;z++)
    if(4*x+5*y+z*7==n)
    printf("%d %d %d",x,y,z);
	printf("\n");
    
    
    }
    return 0;
}
