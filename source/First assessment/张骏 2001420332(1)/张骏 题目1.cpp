#include <stdio.h>
int main()
{char a[60],b[60];int i=0,j=0;
scanf ("%s%s",a,b);
while(a[i]!='\0') i=i+1;
while(b[j]!='\0') j=j+1;
if(i>=j)printf("�����Ϊ%d",i);
else printf("�����Ϊ%d",j);
	return 0;
}