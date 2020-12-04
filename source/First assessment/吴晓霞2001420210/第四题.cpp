#include<stdio.h>

int main()
{int a,b,c,n,t;
int i=0;
printf("输入小明数的窗户数量：\n");
scanf("%d",&n);
printf("输入例程数量：\n");
scanf("%d",&t);
for(a=0;4*a<n;a++)
{ for(b=0;5*b<n;b++)
   { for(c=0;7*c<n;c++)
     {if (4*a+5*b+7*c==n&&i<t)
      {  printf("%d %d %d\n",a,b,c);
      i=i+1;   
      }
     }
    }
}

  printf("n=-1");  
    return 0;
}
