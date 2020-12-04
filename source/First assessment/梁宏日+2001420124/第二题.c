#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//组合去重排序

int getRands(int Ints[]){
	int i =0;
	int num = rand()%10+1;
	for(;i<num;i++){
		Ints[i]=rand()%10;
		printf("%d\t",Ints[i]);
	}
	printf("the end\n");
	return num;
}
void printfun(int c[],int num1,int d[],int num2){
	int a = 0;
	
	while(a<num1){
		printf("%d\t",c[a]);
		a++;
	}

    a = 0;
	while(a<num2){
		printf("%d\t",d[a]);
		a++;
	}
}

void unRepeat(int c[],int num1,int d[],int num2){
//每个参数的意思（数组一，数组一的长度，数组二，数组二的长度）

//合并数组去重复
//排序
//打印出来
int aa[20];
int zcd=1;    //总长度

aa[0]=c[0];
  for(int ii=0;ii<num1;ii++){
    for(int i=0;i<=zcd;i++){
    if(aa[i]==c[ii]){break;}    //检查c的每一项是否与aa重复
    else if(i==zcd-1){aa[zcd]=c[ii];zcd++;}
    }
  }
  //
  for(int ii=0;ii<num2;ii++){
    for(int i=0;i<=zcd;i++){
    if(aa[i]==d[ii]){break;}    //检查b的每一项是否与aa重复
    else if(i==zcd-1){aa[zcd]=d[ii];zcd++;}
    }
  }

/*方法一，使用库函数。
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );}

qsort(aa, zcd, sizeof(aa[0]), cmpfunc);
*/

//方法二，自己写个冒泡。
for(int i=0;i<zcd-1;i++){
  for(int j=0;j<zcd-1;j++){
    if(aa[j]>aa[j+1]){
     int zj=aa[j];
     aa[j]=aa[j+1];
     aa[j+1]=zj;
    }
  };
};


int a = 0;
	while(a<zcd){
		printf("%d\t",aa[a]);
		a++;}


}
int main(){
	srand((unsigned)time(NULL));
	int i=0;
	int c[10];
	int d[10];
	printf("随机生成的第一组数组：\n");
	int num1=getRands(c);
	printf("随机生成的第二组数组: \n");
	int num2=getRands(d);
    printf("处理之前：\n");
	printfun(c,num1,d,num2);
	printf("\n");
	printf("处理之后：\n");
	unRepeat(c,num1,d,num2);
	return 0;
}