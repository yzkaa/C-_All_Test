#include<stdio.h>
main()
{ char a[20],b[20],n1,n2,i,j;
 printf("�ֱ����������ַ�����\n"); 
 gets(a);
 gets(b);
 for(i=0;a[i]!=0;i++)
 n1=i+1;
 for(j=0;b[j]!=0;j++)
 n2=j+1;
 
 if(n1>=n2){
  printf("�Ϊ%d���ַ�\n",n1);
 }
 else{
  printf("�Ϊ%d���ַ�\n",n2); 
 }
 return 0;
}