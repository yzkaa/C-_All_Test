#include<stdio.h>
main()
{ char a[20],b[20],n1,n2,i,j;
 printf("分别输入两个字符串：\n"); 
 gets(a);
 gets(b);
 for(i=0;a[i]!=0;i++)
 n1=i+1;
 for(j=0;b[j]!=0;j++)
 n2=j+1;
 
 if(n1>=n2){
  printf("最长为%d个字符\n",n1);
 }
 else{
  printf("最长为%d个字符\n",n2); 
 }
 return 0;
}