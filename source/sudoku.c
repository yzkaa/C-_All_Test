//���ݷ���������������⣬��ʱ��һ��Ҫ�Լ�дһ��
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define bool int
#define true 1
#define false 0
int sudo[9][9], hole[9][9];
//����������ж����й��Ƿ��г�ͻ�Լ��Ƿ�Ϊ��
bool set(int x, int y, int val)
{
    int x0, y0;
	if (sudo[y][x] != 0)		//�ǿ�
		return false;
	for (x0=0; x0<9; x0++)
	{
		if (sudo[y][x0] == val)	//�г�ͻ
			return false;
	}
	for (y0=0; y0<9; y0++)
	{
		if (sudo[y0][x] == val)	//�г�ͻ
			return false;
	}
	for (y0=y/3*3; y0<y/3*3+3; y0++)
	{
		for (x0=x/3*3; x0<x/3*3+3; x0++)
		{
			if (sudo[y0][x0] == val) //����ͻ
				return false;
		}
	}
	sudo[y][x] = val;
	return true;
}

//���ø�λ�õ�����
void reset(int x, int y)
{
	sudo[y][x] = 0;
}

//����һ��0-9������������飬����������
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

//���ݷ�������������1-9���β���ÿһ�У������Ƚ�1����ÿ��������л�õ�1�����������������ֱ��ÿһ�ж���1��
//�ٴӵ�һ�п�ʼ��֮ǰ�Ĳ�������2��
//����ڲ�������в�����ͻ�����������룬������һ��ѭ����ѡ��һ���µ������������ʼ����
bool fillFrom(int y, int val)
{
	int xOrd[9];
	initXOrd(xOrd);		//���ɵ�ǰ�е�ɨ������
    if(y>=9) return false;
	for (int i=0; i<9; i++)
	{
		int x = xOrd[i];//ѡ��������
		if (set(x, y, val))//�������
		{
			if (y == 8)					//�������һ��
			{
				if (val == 9 || fillFrom(0, val+1))	//��ǰ��9�����, ����ӵ�һ������һ����
					return true;
			} 
			else
			{
				if (fillFrom(y+1, val))	//��һ�м����ǰ��
					return true;
			}
			reset(x, y);//�����һ�εݹ��޷����У�����β���ĵ�ָ���0������ѡ������������жϲ��룬��������ɹ���
                        //��˴εݹ�Ҳ����false��Ȼ��ʹ��һ�εĵݹ��������ѡ�������������ֱ����һ�У��˲�����Ϊ����
		}
	}
	return false;//�޷������򷵻�false
}


//����һ��0-1���飬0��ʾ����
void digHole(int holeCnt)
{
	int idx[81];
	int i, k;
	for (i=0; i<81; i++)
	{
		hole[i / 9][i % 9] = 0;//��һ��ѭ����ʼ����ά����
		idx[i] = i;
	}
	for (i=0; i<holeCnt; i++)	//����ڶ�λ��
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

//�Ѷ�ѡ��
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
        printf("Please select difficulty��input��1 to 3��:");
        scanf("%d",&diff);
    } while(!difficulty(diff));
	printSudoku();
	return 0;
}