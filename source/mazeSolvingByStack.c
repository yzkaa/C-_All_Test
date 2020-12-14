#include<stdio.h>
#include<stdlib.h>
/*************************************Stack begin***************************************/
//定义一个迷宫位置的数据类型，主要存放坐标
typedef struct{
    int x,y;
}dataType; 

//一个结点
struct node{
    dataType location;
	struct node *next; //指向下一个数据元素的指针 
};

//链式栈
typedef struct node *PtrToNode;
typedef PtrToNode Stack;

/*
   函数名：isEmpty 
   函数功能：判定栈是否为空 
   函数参数：栈头结点指针 
   返回值：若栈为空，则返回1，否则返回0
*/
int isEmpty(Stack s) 
{
    return  s->next ==NULL;
}
/*
   函数名：createStack 
   函数功能：创建一个空栈，实际上只需要初始化栈头结点 
   函数参数：无 
   返回值：栈头结点指针 
*/
Stack createStack(void)  
{
	Stack s ;
	s =(Stack)malloc(sizeof(struct node));
	s->next = NULL;
	s->location.x = 0;
    s->location.y = 0;
	return s;
}

/*
   函数名：push 
   函数功能：向栈中压人一个数据元素值为x 
   函数参数：待压栈的数据元素，栈头结点指针 
   返回值：无
*/
void push(dataType coordinate,Stack s) 
{
	//表头作为栈顶
    PtrToNode temp ;
 	temp=(PtrToNode)malloc(sizeof(struct node));
 	temp->location.x = coordinate.x;
    temp->location.y = coordinate.y;
 	temp->next = s->next;
 	s->next = temp;
}

/*
   函数名：pop 
   函数功能：弹出栈顶元素并返回元素值 
   函数参数：栈头结点指针 
   返回值：坐标值 
*/
dataType pop(Stack s) 
{
	PtrToNode temp;
	if(isEmpty(s)==0)
    {
        temp = s->next;
        dataType t;
        t.x = temp->location.x;
        t.y = temp->location.y;
        s->next = temp->next;
        free(temp);
        return t;
    }
}
/*************************************Stack end***************************************/

/*******************************global declarations***********************************/
int set_OK = 0;            //一个flag，用于检测起点和终点是否成功设置。
int maze_row=9;            //地图的行数
int maze_colum=9;          //地图的列数
int i=0,j=0;               //循环变量
char** load_maze(char*);   //载入地图文件
void set_startP_and_endP(char** , dataType* , dataType*);   //设置起点和终点
void depth_first_search(Stack ,char **,dataType,dataType);  //走迷宫，使用深度优先算法
int side_way_num(char ** ,dataType );                       //判断岔路个数

/****************************************main****************************************/
int main(){
    char *  file_location=NULL;         //定义一个文件路径字符串
    char ** maze;                       //二维字符数组，用作地图
    dataType start;                     //一个起点
    dataType end;                       //一个终点
    start.x = start.y = end.x = end.y = -1;     //将起点和终点坐标初始化为-1
    Stack track = NULL;                 //路径栈
    track = createStack();              //开辟一个栈空间
    file_location = (char*)malloc(sizeof(char)*50); //为文件路径字符串分配空间
    printf("Please input the file path of the maze(9x9):\n");
    scanf("%s",file_location);          //输入文件所在路径，绝对路径
    maze = load_maze(file_location);
    printf("Please set start point and end point.\n");
    while(1){
        set_startP_and_endP(maze,&start,&end);
        if(set_OK == 1){
            set_OK=0;
            break;
        }
    }
    push(end,track);
    depth_first_search(track,maze,start,end);
    return 0;
}

char** load_maze(char* file_location){
    FILE *fp=NULL;
    char** maze;
    char** error;
    char tmp = 0;
    // while(!feof(fp)){
    //     tmp = fgetc(fp);
    //     if(tmp == '\n'){
    //         ++maze_row;
    //         maze_colum = 0;
    //     }
    //     if(tmp>=48&&tmp<=57){
    //         ++maze_colum;
    //     }
    // }
    // rewind(fp);
    maze = (char **)malloc(sizeof(char*)*maze_row);
    for(i=0;i<maze_colum;i++){
        maze[i] = (char *)malloc(sizeof(char)*maze_colum);
    }
    if((fp = fopen(file_location,"r"))==NULL){
        perror("Faild to load maze");
        return error;
    }
    i=0;
    while(i<maze_row){
        j=0;
        while(j<maze_colum){
            tmp = fgetc(fp);
            if(tmp <48 || tmp >57) continue;
            maze[i][j] = tmp;
            j++;
        }
        i++;
    }
    printf("Finished loading.\n");
    fclose(fp);
    return maze;
}

void set_startP_and_endP(char** maze, dataType* start_point,dataType* end_point){    

    //确定起点坐标
    if(start_point->x < 0||start_point->y < 0){
        printf("Start point(x,y):");
        scanf("%d,%d",&start_point->x,&start_point->y);
        if(start_point->x<0||start_point->y<0){
            printf("Input range error(0 ~ mazeSize-1),Please try again.\n");
            return;
        }
    }  
    if(maze[start_point->y][start_point->x]!='1'){
        printf("Wrong start location!Please try again.\n");
        start_point->x = start_point->y = -1;
        return;
    }

    //确定终点坐标
    if(end_point->x < 0||end_point->y < 0){
        printf("End point(x,y):");
        scanf("%d,%d",&end_point->x,&end_point->y);
        if(end_point->x<0||end_point->y<0){
            printf("Input range error(0 ~ mazeSize-1),Please try again.\n");
            return;
        }
    }  
    if(maze[end_point->y][end_point->x]!='1'){
        printf("Wrong end location! Please try again.\n");
        end_point->x = end_point->y = -1;
        return;
    }


    printf("Set complete.\n");
    set_OK =1;
}

//使用栈进行迷宫反向遍历，深度优先遍历
void depth_first_search(Stack s,char **maze,dataType start,dataType end){
    dataType temp;
    int sideWays=0;
    int moveFlag=0;
    while(!isEmpty(s)){
        moveFlag=0;
        temp = pop(s);
        if(temp.x == start.x && temp.y == start.y){
            printf("The track of the maze is: start->");
            while(!isEmpty(s)){
                printf("(%d,%d)->",temp.x,temp.y);
                temp = pop(s);
            }
            printf("(%d,%d)->",end.x,end.y);
            printf("end");
            return;
        }
        sideWays = side_way_num(maze,temp);
        if(sideWays==0){
            continue;
        }
        push(temp,s);

        maze[temp.y][temp.x]='2';
        //按照顺序进行搜索 右左上下
        if(temp.x+1<maze_colum && moveFlag==0){
            if( maze[temp.y][temp.x+1] == '1'){
                temp.x = temp.x+1;
                push(temp,s);
                maze[temp.y][temp.x] = '2';
                moveFlag=1;
                continue;
            }
        }
        if(temp.x-1>=0 && moveFlag==0){
            if( maze[temp.y][temp.x-1] == '1'){
                temp.x = temp.x-1;
                push(temp,s);
                maze[temp.y][temp.x] = '2';
                moveFlag=1;
                continue;
            }
        }
        if(temp.y-1>=0 && moveFlag==0){
            if( maze[temp.y-1][temp.x] == '1'){
                temp.y = temp.y-1;
                push(temp,s);
                maze[temp.y][temp.x] = '2';
                moveFlag=1;
                continue;
            }
        }
        if(temp.y+1<maze_row && moveFlag==0){
            if( maze[temp.y+1][temp.x] == '1'){
                temp.y = temp.y+1;
                push(temp,s);
                maze[temp.y][temp.x] = '2';
                moveFlag=1;
                continue;
            }
        }
        printf("x:%d,y:%d\n",temp.x,temp.y);
    }
    printf("This maze has no track.\n");
    return;
}

int side_way_num(char **maze,dataType location){
    int sideWay=0;
    //向右进行探索
    if(location.x+1<maze_colum){
        if(maze[location.y][location.x+1] == '1'){
            ++sideWay;  
        }
    }

    //向左进行探索
    if(location.x-1>=0){
        if( maze[location.y][location.x-1] == '1'){
            ++sideWay;
        }
    }

    //向上进行探索
    if(location.y-1>=0){
        if( maze[location.y-1][location.x] == '1'){
            ++sideWay;
        }
    }

    //向下进行探索
    if(location.y+1<maze_row){
        if( maze[location.y+1][location.x] == '1'){
            ++sideWay;
        }
    }
    printf("sideWay:%d\n",sideWay);
    return sideWay;
}