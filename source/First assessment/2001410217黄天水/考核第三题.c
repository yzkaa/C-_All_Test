#include<stdio.h>
#include<math.h>
int main()
{
    int i,j;
	float matrix[3][3];
	const double eps=1E-6;
	printf("������Ԫ�أ�");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%f",&matrix[i][j]);
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(fabs(matrix[i][j]-3.14)<=eps)
			printf("����3.14��ֵ�кţ�%d���кţ�%d\n",i,j);
		}
	}
		printf("�������:\n");
    for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		    printf("%.2f\t",matrix[i][j]);
		}
		printf("\n");
	}
    return 0;
}
