#include <stdio.h>
void check(float matrix[][3])
{int i,j;float k,l;
for(i=0;i<3;i++)
  for(j=0;j<3;j++)
  {if(matrix[i][j]<3.14){ k=3.14-matrix[i][j];
     if(k<0.000001) printf("坐标为:%d,%d\n",i,j);}
  else {k=matrix[i][j]-3.14;if(k<0.000001) printf("坐标为:%d,%d\n",i,j);}}}	
void insert(float matrix[][3])
{int i,j;
for(i=0;i<3;i++)
    for(j=0;j<3;j++)
	{scanf("%f",*(matrix+i)+j);}
}
int main()
{float matrix[3][3];int i,j;
insert(matrix);
for(i=0;i<3;i++)
 {
	for(j=0;j<3;j++)
	{printf("%4.2f\t",matrix[i][j]);
	printf("\n");}}
check(matrix);		
return 0;
		}
