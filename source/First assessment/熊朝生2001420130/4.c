#include<stdio.h>

int main()
{
    int i=-1,j=-1,k=0,t;
    printf("�����봰��������");
    scanf("%d",&t);
    for(i=-1; (4*i+5*j+7*k!=t)&&i<200; )
    {
        i++;
        for(j=-1; (4*i+5*j+7*k!=t)&&j<200; )
        {
            j++;
            for(k=0; (4*i+5*j+7*k!=t)&&k<200; )
            {
                k++;
            }
        }
    }
    if(i==200&&j==200&&k==200)
        printf("\n�����˰ɣ�");
    else
        printf("����:%d\t����:%d\t����:%d",i,j,k);
}
