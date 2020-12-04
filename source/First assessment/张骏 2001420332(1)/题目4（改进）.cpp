#include<stdio.h>
int main(){
	int a,b,c,x,t,y,d,e,f,g;
   scanf("%d/n",&t);
   for(y=0;y<t;y++)
   {scanf("%d",&x);if(x==4||x==5||x>6){//判断结果是否为-1
   d=x/4;e=x/5;f=x/7;g=1;//考虑户型数量最大值
   for(a=0;a<=d;a++){if(g==0) break;
	   else for(b=0;b<=e;b++){if(g==0) break;
	     else for(c=0;c<=f;c++)
			 if(a*4+b*5+c*7==x){ printf("%d%d%d\n",a,b,c);g=0;break;;;;}}}}
   else {printf("-1");break;} 
   }
	return 0;
}
