#include <stdio.h>
void f(int nums[100])
{int i,j=0;char ch;
   for(i=0;i<10000;i++){
	   scanf("%d%c",&nums[i],&ch);if(ch=='\n') break;//�жϻس�ֹͣ����
   };
   for(i=1;i<10000;i++){if(nums[i-1]>nums[i]){ j=j+1;//ǰ����ں���Ĵ�������j
   if(i>1) {if(nums[i-1]==nums[i-2]) j=j+1;}}//����2��2��1���������ں�������
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
