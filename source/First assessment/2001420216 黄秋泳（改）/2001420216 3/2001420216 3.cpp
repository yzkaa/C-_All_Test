#include <stdio.h>
float insert(int,int);
void check(float,float,float,float,float,float,float,float,float);
int main()

{
    int i,j;
    float x = 3.14;
    float a,b,c,d,e,f,g,h,n;
    float matrix[3][3];
    printf("������9������\n");
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
        matrix[i][j] = insert(i,j);
        }
    }
    a = matrix[0][0];
    b = matrix[0][1];
    c = matrix[0][2];
    d = matrix[1][0];
    e = matrix[1][1];
    f = matrix[1][2];
    g = matrix[2][0];
    h = matrix[2][1];
    n = matrix[2][2];
    check(a,b,c,d,e,f,g,h,n);
	printf("\n�������\n");
    for(i = 0;i < 3;i++)
    {
        for(j = 0;j < 3;j++)
        {
        printf("%4.2f",matrix[i][j]);
        }
    }

}

float insert(int i,int j)
{
    float n;
    scanf("%f",&n);
    return n;
}

void check(float a,float b,float c,float d,float e,float f,float g,float h,float n)
{
    float x = 3.14;
    if(x==a)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",0,0);
    if(x==b)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",0,1);
    if(x==c)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",0,2);
    if(x==d)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",1,0);
    if(x==e)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",1,1);
    if(x==f)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",1,2);
    if(x==g)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",2,0);
    if(x==h)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",2,1);
    if(x==n)
    printf("����3.14��ֵ�кţ�%d���кţ�%d\n",2,2);
}