#include<stdio.h>

int main()
{
    int d=0,f=0,i;
    char a[6],b[6];
	printf("�����������ַ�����ÿ���ַ�������Ͽո���ÿ���ַ������ó���5���ַ�\n");
    for(i=0;i<=6;i++)
    {
       scanf("%c",&a[i]);
       if(a[i]==' ')
         break;
       d++;
    }
    for(i=0;i<=6;i++)
    {
       scanf("%c",&b[i]);
       if(b[i]==' ') break;
       f++;
    }
    if(d>=f)
      for(i=0;i<d;i++)
         printf("%c",a[i]);
    else
      for(i=0;i<f;i++)
         printf("%c",b[i]);
	  printf("\n");
    return 0;
}