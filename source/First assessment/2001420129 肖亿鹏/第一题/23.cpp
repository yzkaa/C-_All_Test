#include<stdio.h>
void main()
{
	char a[20],b[20];int i,k;
	for(i=0;i<20;i++)
		a[i]=0;
	for(k=0;k<20;k++)
		b[k]=0;
    scanf("%s",a);
    scanf("%s",b);
	for(i=0;a[i]!=0;i++)
	{}
	for(k=0;b[k]!=0;k++){}
	if(i>k) printf("���Ϊ%d���ַ�\n",i);
    if (i<k) printf("���Ϊ%d���ַ�\n",k);


}