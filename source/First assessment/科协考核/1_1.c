#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {
	char *p = NULL;
	char *q = NULL;
	p = (char *)malloc(sizeof(char));
	q = (char *)malloc(sizeof(char));
	printf("please input the first string: ");
    scanf("%s", p);//�����ַ���
   	printf("please input the first string: ");
   	scanf("%s", q);
	int len1 = strlen(p);
   	int len2 = strlen(q);
	printf("�Ϊ%d���ַ�",len1>len2?len1:len2);
	
    free(p);
    free(q);
    p = NULL;
    q = NULL;
	return 0;
}
