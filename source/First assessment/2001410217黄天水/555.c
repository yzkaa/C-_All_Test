#include<stdio.h>
int main()
{
	int n,i,a=0,nums[]={3,4,2,3};
	n=sizeof(nums)/4;
	for(i=0;i<n-1;i++)
	{
	   if(nums[i]>nums[i+1]&&i==0)
	   {
		  nums[i]=nums[i+1];
		  break;
	   }
	   else if(nums[i]>nums[i+1]&&i!=(n-1))
	   {
		   a=nums[i];
		   nums[i]=nums[i-1];
           if(nums[i]<=nums[i+1])
		      break;
		   else
		   {
               nums[i]=a;
			   nums[i+1]=nums[i+2];
			   break;
		   }
	   }
	   else if(nums[i]<=nums[i+1]&&i==(n-1))
		   nums[i+1]=nums[i];
	}//¸ÄÕı
	a=0;
	for(i=0;i<n-1;i++)
	{
	   if(nums[i]<=nums[i+1]) 
		  a++;
	}
   	if(a==(n-1))
	{
      printf("trun\n");
	}
    else
		printf("ftrue\n");
	
return 0;
}
