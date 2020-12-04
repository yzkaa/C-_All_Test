#include<stdio.h>
int main()
{int t,d,g,w,h,a4,a5,a7;
printf("请输入列程数量:");
scanf("%d",&t);
for(d=0;d<t;d++){
	printf("\n请输入窗户数量:");
	scanf("%d",&w);
	switch(w){
	case(1):
    case(2):
    case(3):
    case(6):printf("-1\n");break;
	default:{
	for(a7=0,h=1;h>0;){
		g=w-7*a7++;
		for(a5=0;(h>a5*5)||(h==5);){
			h=g-5*(a5++),a4=0;
			if((h%4==0)&&(h>0)) a4=h/4,h=0;
	}}
	printf("%d,%d,%d\n",a4,a5-1,a7-1);}
}}
return 0;}
