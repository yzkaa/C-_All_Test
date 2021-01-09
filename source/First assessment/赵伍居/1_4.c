#include <stdio.h>

int a[10010];
int n;
void init()//初始化 懂的都懂 
{
	int i;
	printf("input school number:"); 
	scanf("%d",&n);//输入门派有多少人 
	printf("resources:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		
	}
}
void swap(int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
int isabnormal()//判断是否异常 0没有异常 1异常 
{
	int state=0;//
	int i=0;
	for(i=0;i<n-1;i++)
	{
		//printf("%d %d\n",a[i],a[i+1]);
		if(a[i]>a[i+1])
		{
			state++;
			swap(i,i+1);
			if(state>1)
			return 0;
		}	
	} 
	return 1;
}
int main()
{

	int i,j;
	int k=0;
	int n;
	init();
	k=isabnormal();
	if(!k) printf("false");
	else printf("true");
	return 0;
}
