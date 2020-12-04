#include<stdio.h>
void outputwindows(int n)
{
	int max=0,fac4=0,fac5=0,fac7=0,i=0;
	if(n<4||n==6)printf("-1\n");
	else
	{
		if(n%5==0&&n%7!=0)fac5=n/5;
		if(n%7==0)fac7=n/7;
		if(n%7!=0&&n%5!=0)
		{
			max=n/4;fac4=n/4;
			for(i=1;i<=max;i++)
			{					
				if((n-4*fac4)%5==0)
					fac5=(n-4*fac4)/5;
				else 
					if((n-4*fac4)%7==0)
						fac7=(n-4*fac4)/7;
					else 
						fac4--;				
			} 
		}
		printf("%d %d %d\n",fac4,fac5,fac7);
	}
}
int main()
{
	int t=0,n=0,i=0;
	printf("请输入例程数量:");
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("请输入窗户数量:");
		scanf("%d",&n);
		outputwindows(n); 
	}
}
