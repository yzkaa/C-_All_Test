#include<stdio.h>
void main()
{
	int n;
	int i=0;
	int j=0;
	int nums[10000];
	printf("input school number£º\n");
	scanf("%d", &n);


    if(n>1)
	{
		printf("\nresources£º");
        for(i=0; i<n; i++)
		{
			scanf("%d", &nums[i]);
		}
    	for(i=0; i<(n-1); i++)
		{
			if(nums[i]>nums[i+1])
				j=j+1;
		}
		if(j<=1)
			printf("true\n");
		else
			printf("flase\n");
	}
    if(n==1)
	{
		printf("There was only one man \n");
		printf("true\n");
	}
    if(n<1)
		printf("error\n");
}
