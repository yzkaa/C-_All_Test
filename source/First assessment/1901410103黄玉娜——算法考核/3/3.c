#include<stdio.h>
float insert(float matrix[3][3])
{
    int i;
    int j;
    printf("������ڷ������ݣ�\n");
    for(i=0; i<3; i++)
    {   for(j=0; j<3; j++)
        {   scanf("%f",&matrix[i][j]);
        }
    }
	printf("����\n");
    for(i=0; i<3; i++)
    {   for(j=0; j<3; j++)
        {
		printf("%4.2f\t",matrix[i][j]);

  		if(j==2)
			printf("\n");
        }
    }
}
void check(float matrix[3][3])
{
    int i,j;
	int m=0;
	int n=0;
    float k=3.14;
    for(i=0; i<3; i++)
    {   for(j=0; j<3; j++)
        {   if(matrix[i][j]==k)
            {   m=i+1;
                n=j+1;
                printf("����3.14��Ԫ�ص��к�Ϊ%d\n%",m);
                 printf("����3.14��Ԫ�ص��к�Ϊ%d\n",n);
				 printf("\n");
            }
        }
    }
}
void main()
{
    float matrix[3][3];

    insert(matrix);
    check(matrix);
   
}
