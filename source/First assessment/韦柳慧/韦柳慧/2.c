#include<stdio.h>
#include <stdlib.h>
#include <time.h>
//���ȥ������

int getRands(int Ints[]) {
    int i = 0;
    int num = rand()%10+1;
    for(; i<num; i++) {
        Ints[i]=rand()%10;
        printf("%d\t",Ints[i]);
        
    }
    printf("the end\n");
    return num;
}
void printfun(int c[],int num1,int d[],int num2) {
    int a = 0;
    
    while(a<num1) {
        printf("%d\t",c[a]);
        a++;
        
    }

    a = 0;
    while(a<num2) {
        printf("%d\t",d[a]);
        a++;
        
    }
}

void unRepeat(int c[],int num1,int d[],int num2) { //ÿ����������˼������һ������һ�ĳ��ȣ��������������ĳ��ȣ�
    int n1,n2,n3,n4,n5,n6,n7;
    int flag=0;
	int length=num1+num2;
    int x[length];
    int temp=0;
    for(n1=0; n1<num1; n1++)
        x[n1]=c[n1];
    for(n2=0; n2<num2; n2++)
        x[n2+num1]=d[n2];//����������ϲ�������һ��������
    
    for(n6=0; n6<length-1; n6++)
        for(n7=0; n7<length-n6-1; n7++)
            if(x[n7]>x[n7+1])
            {
                temp=x[n7];
                x[n7]=x[n7+1];
                x[n7+1]=temp;
            }//����

	for(n3=0; n3<length-flag; n3++)
        for(n4=n3+1; n4<length-1-flag; n4++)
            if(x[n3]==x[n4]){
                for(n5=n4; n5<length-flag-1; n5++)
                    x[n5]=x[n5+1];
                n4--;
                flag++;
            }//���ز�ɾ��

	for(n1=0; n1<length-flag; n1++)
		printf("%d  ",x[n1]);
}
int main() {
    srand((unsigned)time(NULL));
    int i=0;
    int c[10];
    int d[10];
    printf("\n");
    printf("\n");
	printf("������ɵĵ�һ�����飺\n");
	int num1=getRands(c);
	printf("������ɵĵڶ�������: \n");
	int num2=getRands(d);
	printf("����֮ǰ��\n");
	printfun(c,num1,d,num2);
	printf("\n");
	printf("����֮��\n");
	unRepeat(c,num1,d,num2);
	
    return 0;
}
