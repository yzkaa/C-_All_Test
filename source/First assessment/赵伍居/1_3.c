#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
float ** insert()
{
	float **p = NULL;
	int i = 0, j = 0;
	float s[3][3];
	for(i=0; i<3; i++)
		for(j=0; j<3; j++) {
			scanf("%f",&s[i][j]);
		}

	p = (float **)malloc(sizeof(float *) * 3);
	for (i = 0; i < 3; i++)
	{
		p[i] = (float *)malloc(sizeof(float) * 3);
		for (j = 0; j < 3; j++)
		{
			p[i][j] = s[i][j];
		}
	}
	return p;
}
void check(float ** s){
	int i=0,j=0;
	float delta = 0.00001;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			float x = s[i][j] - 3.14;
			if((x >= - delta) && (x <= delta))
				printf("等于3.14的值的行号：%d，列号：%d\n",i+1,j+1);
		}
	}
	printf("\n");
}
int main() {
	printf("please input the matrix's value: \n");
	float ** s;
	s = insert();
	printf("\n");
	check(s);
	int i=0,j=0;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++)
			printf("%4.2f\t",s[i][j]);
		printf("\n");
	} 
}
