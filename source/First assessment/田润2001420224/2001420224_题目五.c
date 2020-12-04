#include<stdio.h>
void nums_check(int n,int nums[])
{
	int i,j,t=0,m,ans=0;
	m=n;
	int sums[m];
	for(i=0;i<n;i++)sums[i]=nums[i];
	for(j=0;j<n-1;j++)
		for(i=0;i<n-1-j;i++)
			if (sums[i]>sums[i+1])
				{t=sums[i];sums[i]=sums[i+1];sums[i+1]=t;}
	for(i=0;i<n;i++)
		if(sums[i]!=nums[i])ans++;
	if(ans<=2)printf("true");
	else printf("false");
}
int main()
{
	int i=0,n;
	printf("input school number:\n");
	scanf("%d",&n);
	int nums[10];
	printf("resources:\n");
	for(i=0;i<n;i++)
		scanf("%d",&nums[i]);
	nums_check(n,nums);
	return 0; 
} 
