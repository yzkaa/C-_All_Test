#include<string.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
int dfs(int x,int y);//深度优先
int judge(int i,int j,int num);
int flag ;
int a[15][15];//声明数组
int main()
{
	int i,j;
	char b[10];
	for(i=1;i<=9;i++)
	{
		gets(b);
		for(j=1;j<=9;j++)
			a[i][j]=b[j-1]-48;//录入
	}
	dfs(1,1);
 
	return 0;
}
 
int dfs(int x,int y)
{
    //加上flag，表示其输出一个符合条件的答案就退出
	int i,j;
    if(flag) return 0;
	if(x==10)//满足条件输出
	{
	    flag = 1;
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
				printf("%d",a[i][j]);
			printf("\n");
		}
		return 0;
	}
 
	if(a[x][y]==0)//判断是否有数
	{
		for(i=1;i<=9;i++)
		{
			if(judge(x,y,i))
			{
				a[x][y]=i;
				dfs(x+(y+1)/10,(y+1)%10);//往后一个数，到头换行
			}
		}
		a[x][y]=0;//回溯
	}
	else
		dfs(x+(y+1)/10,(y+1)%10);//有数则下一个
	return 0;
}
 
int judge(int i,int j,int num)//判断是否满足条件
{
	int k,x,y,l;
	if(i%3==0)  y=i/3;//得出第几个方块（纵）
	else 		y=i/3+1;
 
	if(j%3==0)  x=j/3;//得出横着第几个方块
	else 		x=j/3+1;
 
	for(k=1;k<=9;k++)//判断一行是否有重复的
		if(a[i][k]==num&&k!=j)   return 0 ;
	for(k=1;k<=9;k++)  //判断一列是否有重复的
		if(a[k][j]==num&&k!=i)   return 0 ;
	for(k=(y-1)*3+1;k<=y*3;k++)//判断该方块中是否有重复的
		for(l=(x-1)*3+1;l<=x*3;l++)
			if(a[k][l]==num&&k!=i&&l!=j)
				return 0;
	return 1;
}