#include <stdio.h>
int main()
{
	char str1[100], str2[100];
	int n1=0, n2=0;
	printf("分别输入两个字符串：\n");
	scanf("%s%s", str1, str2);           //输入

	for (int i = 0; str1[i] != '\0'; i++)
		n1++;
	for (int i = 0; str2[i] != '\0'; i++)
		n2++;                            //判断字符串长度

	if (n1 >= n2)
		printf("最长为%d个字符\n", n1);
	else
		printf("最长为%d个字符\n", n2);  //比较、输出

	return 0;
}