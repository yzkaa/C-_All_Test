#include<stdio.h>
int main() {
float a[3][3];
int i,j;
float f,d;
for(i=0;i<3;i++){
    for(j=0;j<3;j++){
        printf("ÇëÊäÈëa(%d,%d)=",i,j);
		scanf("%f",&d);
		a[i][j]=d;}}
for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		f=a[i][j]-3.14;
	   if(f<1e-6&&f>0) printf("a(%d,%d)=%f\n",i,j,a[i][j]);
}}
return 0;}
