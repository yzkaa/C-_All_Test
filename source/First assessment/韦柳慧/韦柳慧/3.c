#include<stdio.h>
int main()
{
    double inster(double score[][]);//对inster函数做声明
    double check(double score[][]);//对check函数做声明
    double score[3][3];
    printf("请输入元素:");
    int i=0,j=0;
    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
           scanf("%f",&score[i][j]);
    inster(score[3][3]);//调用inster函数
    check(score[3][3]);//调用check函数
    return 0;
}
double inster(double score[][]);//定义inster函数
{
    double score[3][3];
    int i=0,j=0;
    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
           scanf("%f",&score[i][j]);
           return (score[i]score[j]);
}
double check(double score[][])//定义check函数
{
    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
          if(score[i][j]=3.14)
            printf("这是第%.2lf行,第%.2lf列元素",i,j);
            return (score[i]score[j]);
}
