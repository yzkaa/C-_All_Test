#include<stdio.h>  
int main()

{ 
 float a[3][3],Pl=3.14;
 int i,j;
 printf("���������Ԫ��");
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
   scanf("%f",&a[i][j]);
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
    if(a[i][j]==Pl)
     printf("����3.14��ֵ�кţ�%d���кţ�%d",i,j);
	printf("\n");

for(i=0;i<3;i++)
{
        for(j=0;j<3;j++)
    {
            printf("%f ",a[i][j]);
    }
    printf("\n");
}
return 0;
}
