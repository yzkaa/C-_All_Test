#include<stdio.h>
int main()
{
    double inster(double score[][]);//��inster����������
    double check(double score[][]);//��check����������
    double score[3][3];
    printf("������Ԫ��:");
    int i=0,j=0;
    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
           scanf("%f",&score[i][j]);
    inster(score[3][3]);//����inster����
    check(score[3][3]);//����check����
    return 0;
}
double inster(double score[][]);//����inster����
{
    double score[3][3];
    int i=0,j=0;
    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
           scanf("%f",&score[i][j]);
           return (score[i]score[j]);
}
double check(double score[][])//����check����
{
    for(i=0;i<3;i++)
       for(j=0;j<3;j++)
          if(score[i][j]=3.14)
            printf("���ǵ�%.2lf��,��%.2lf��Ԫ��",i,j);
            return (score[i]score[j]);
}
