#include<stdio.h>
int aaa(int a);
int main()
{
    int b,t,n,m,z;
	printf("请输入例程数量：");
	scanf("%d",&t);
    for(m=0;m<t;m++)
	{
		printf("请输入窗户数量:");
		scanf("%d",&z);
		b=aaa(z);
	}
	return 0;
}
int aaa(int z)
{
	int i,j,k;
    	for(i=0;i<10;i++)
			for(j=0;j<10;j++)
				for(k=0;k<10;k++)
				{
				    if(i*4+j*5+k*7==z) 
					{
						printf("%d  %d  %d\n",i,j,k);
					    return 0;
					}
				}
}
