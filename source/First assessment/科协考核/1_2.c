#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void unRepeat(int c[],int num1,int d[],int num2){//ÿ����������˼������һ������һ�ĳ��ȣ��������������ĳ��ȣ�
	int i = 0;
	int j = 0;
	int flag = 0;
	int k = 0;
	int length = num1 + num2;
	int s[length];
	for(i=0; i<num1; i++){   // ����ϲ� 
		s[i]=c[i];
	}
	for(i=0; i<num2; i++){
		s[i+num1]=d[i];
	}
	for(i=0; i<length-1; i++)// ð������ 
		for(j=0; j<length-i-1; j++){
			int temp=0;
			if(s[j]>s[j+1]){
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	for(i=0; i<length-flag; i++)
		for(j=i+1;j<length-flag-1;j++)
			if(s[i]==s[j]){
				for(k=j; k<length-flag-1; k++)
					s[k]=s[k+1];
				j--;
				flag++;
			}
	for(i=0; i<length-flag-1; i++)
		printf("%d ",s[i]);
}
int main(){
	srand((unsigned)time(NULL));
	int i=0;
	int c[10];
	int d[10];
	printf("������ɵĵ�һ������:\n");
	int num1=getRands(c);
	printf("������ɵĵڶ�������: \n");
	int num2=getRands(d);
    printf("����֮ǰ:\n");
	printfun(c,num1,d,num2);
	printf("\n");
	printf("����֮��:\n");
	unRepeat(c,num1,d,num2);
	return 0;
}
