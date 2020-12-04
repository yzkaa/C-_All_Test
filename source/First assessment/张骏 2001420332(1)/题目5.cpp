#include <stdio.h>
void f(int nums[100])
{int i,j=0;char ch;
   for(i=0;i<10000;i++){
	   scanf("%d%c",&nums[i],&ch);if(ch=='\n') break;//判断回车停止输入
   };
   for(i=1;i<10000;i++){if(nums[i-1]>nums[i]){ j=j+1;//前面大于后面的次数赋予j
   if(i>1) {if(nums[i-1]==nums[i-2]) j=j+1;}}//考虑2，2，1类连续大于后面的情况
   if(nums[i+1]==0) break;
   }
if(j>1) printf("false");
   else printf("ture");	 
}
   int main(){
	   int nums[10000]={0}; int i,j;
  f(nums);
	return 0;
}
