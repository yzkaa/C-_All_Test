#include<stdio.h>
void insert1(float a[3][3]);
void check(float a[3][3]);
int main()
{
    float matrix[3][3];
    insert1(matrix);
    check(matrix);
    return 0;
}
void insert1(float a[3][3])
{
    int i,j;
    printf("请键入插入元素：");
    for(i=0;i<3;i++)
	{
        for(j=0;j<3;j++)
		{
            scanf("%f",&a[i][j]);
        }
    }
}

void check(float a[3][3])
{
    int i,j;
    float n=3.14;
    for(i=0;i<3;i++)
	{
        for(j=0;j<3;j++)
		{
            if(a[i][j]==n)
			{
                printf("等于3.14的值行号：%d，列号：%d\n",i++,j++); 
            }
        }
    }
    printf("\n");
    for(i=0;i<3;i++)
	{
        for(j=0;j<3;j++)
		{
			printf("%4.2f\t",a[i][j]);
		}
	printf("\n");
	}
    
}
