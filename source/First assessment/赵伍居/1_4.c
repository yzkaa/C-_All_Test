#include <stdio.h>

int a[10010];
int n;
void init()//��ʼ�� ���Ķ��� 
{
	int i;
	printf("input school number:"); 
	scanf("%d",&n);//���������ж����� 
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
int isabnormal()//�ж��Ƿ��쳣 0û���쳣 1�쳣 
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
