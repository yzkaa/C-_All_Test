#include <stdio.h>
int main()
{
	char str1[100], str2[100];
	int n1=0, n2=0;
	printf("�ֱ����������ַ�����\n");
	scanf("%s%s", str1, str2);           //����

	for (int i = 0; str1[i] != '\0'; i++)
		n1++;
	for (int i = 0; str2[i] != '\0'; i++)
		n2++;                            //�ж��ַ�������

	if (n1 >= n2)
		printf("�Ϊ%d���ַ�\n", n1);
	else
		printf("�Ϊ%d���ַ�\n", n2);  //�Ƚϡ����

	return 0;
}