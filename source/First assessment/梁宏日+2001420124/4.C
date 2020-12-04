#include <stdio.h>

int chs(int a){
  if(a<4){printf("-1\n");return ;}
  for(int h=0;h<=a/4;h++){
    for(int i=0;i<=a/5;i++){
      for(int j=0;j<=a/7;j++){
        if((h*4+i*5+j*7)==a){
          printf("%d %d %d\n",h,i,j);
          return  ;
        }
   }}}
   printf("-1");
  };

void main(){
  int t,n;
  printf("请输入例程数"),
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    printf("请输入窗户数量：");
    scanf("%d",&n);
    chs(n);
  };
return 0;
}

// 4 5 7凑出n
