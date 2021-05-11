//回溯法解决数独生成问题，有时间一定要自己写一次
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define bool int
#define true 1
#define false 0
int sudo[9][9], hole[9][9];
//插入操作，判断行列宫是否有冲突以及是否为空
bool set(int x, int y, int val)
{
    int x0, y0;
	if (sudo[y][x] != 0)		//非空
		return false;
	for (x0=0; x0<9; x0++)
	{
		if (sudo[y][x0] == val)	//行冲突
			return false;
	}
	for (y0=0; y0<9; y0++)
	{
		if (sudo[y0][x] == val)	//列冲突
			return false;
	}
	for (y0=y/3*3; y0<y/3*3+3; y0++)
	{
		for (x0=x/3*3; x0<x/3*3+3; x0++)
		{
			if (sudo[y0][x0] == val) //宫冲突
				return false;
		}
	}
	sudo[y][x] = val;
	return true;
}

//重置该位置的数字
void reset(int x, int y)
{
	sudo[y][x] = 0;
}

//生成一个0-9的随机排列数组，用作列坐标
void initXOrd(int* xOrd)	
{
	int i, k, tmp;
	for (i=0; i<9; i++)
	{
		xOrd[i] = i;
	}
	for (i=0; i<9; i++)
	{
		k = rand() % 9;
		tmp = xOrd[k];
		xOrd[k] = xOrd[i];
		xOrd[i] = tmp;
	}
}

//回溯法生成数独，将1-9依次插入每一行，即：先将1按照每次随机序列获得的1的列坐标插入数独，直到每一行都有1，
//再从第一行开始按之前的操作插入2，
//如果在插入过程中产生冲突，则跳过插入，进入下一次循环，选择一个新的列坐标继续开始插入
bool fillFrom(int y, int val)
{
	int xOrd[9];
	initXOrd(xOrd);		//生成当前行的扫描序列
    if(y>=9) return false;
	for (int i=0; i<9; i++)
	{
		int x = xOrd[i];//选择列坐标
		if (set(x, y, val))//插入操作
		{
			if (y == 8)					//到了最后一行
			{
				if (val == 9 || fillFrom(0, val+1))	//当前填9则结束, 否则从第一行填下一个数
					return true;
			} 
			else
			{
				if (fillFrom(y+1, val))	//下一行继续填当前数
					return true;
			}
			reset(x, y);//如果下一次递归无法进行，则将这次插入的点恢复成0，重新选择列坐标进行判断插入，如果都不成功，
                        //则此次递归也返回false，然后使上一次的递归进行重新选择列坐标操作，直到第一行，此操作称为回溯
		}
	}
	return false;//无法插入则返回false
}


//创建一个0-1数组，0表示不挖
void digHole(int holeCnt)
{
	int idx[81];
	int i, k;
	for (i=0; i<81; i++)
	{
		hole[i / 9][i % 9] = 0;//用一次循环初始化二维数组
		idx[i] = i;
	}
	for (i=0; i<holeCnt; i++)	//随机挖洞位置
	{
		k = rand() % 81;
		int tmp = idx[k];
		idx[k] = idx[i];
		idx[i] = tmp;
	}
	for (i=0; i<holeCnt; i++)
	{
		hole[idx[i] / 9][idx[i] % 9] = 1;
	}
}

void printSudoku()
{
	for (int y=0; y<9; y++)
	{
		for (int x=0; x<9; x++)
		{
			(hole[y][x] == 0) ? (printf("%d ",sudo[x][y])) : (printf("  "));
		}
		printf("\n");
	}
}

//难度选择
bool difficulty(int idx){
    if(idx==1){
        digHole(40);
        return true;
    } else if(idx==2){
        digHole(50);
        return true;
    }else if(idx==3){
        digHole(60);
        return true;
    }else{
        printf("wrong input\n");
        return false;
    }
}

int main(int argc, char* argv[])
{	
    int diff=0;
    srand((unsigned)time(NULL));
	while (!fillFrom(0, 1)) ;
	do{
        printf("Please select difficulty（input：1 to 3）:");
        scanf("%d",&diff);
    } while(!difficulty(diff));
	printSudoku();
	return 0;
}