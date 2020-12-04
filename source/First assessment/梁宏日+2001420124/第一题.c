#include <stdio.h>
int main(){
  char a;
  int cd1=0,cd2=0;
    printf("先后输入两个字符串：\n");
    while((a=getchar())!='\n'){cd1++;};
    while((a=getchar())!='\n'){cd2++;};
//    printf("%d,%d",cd1,cd2);
  if(cd1>cd2){printf("长达%d个字符",cd1);}
  else{printf("长达%d个字符",cd2);}
return 0;
}