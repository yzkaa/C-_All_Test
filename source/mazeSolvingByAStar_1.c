#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define TURE 1
#define FALSE 0
int i,j;
int maze_row=0;            //地图的行数
int maze_colum=0;          //地图的列数
typedef struct LNode {
    char data;                   //对应数组中的数值
    int F;                      //F = G + H;
    int G;                      //G：从起点 A 移动到指定方格的移动代价，沿着到达该方格而生成的路径
    int H;                      //H：从指定的方格移动到终点 B 的估算成本
    int x, y;                   //对应数组中的坐标
    bool OPen_flag;             //在开放列表中为1，不在为0
    bool Close_flag;            //在关闭列表中为1，不在为0
    struct LNode* next;         //用于链表排序
    struct LNode* path_next;    //用于最终找到的路径
}LNode, *LinkList;

LinkList InitList(); //返回一个初始化的链表
LNode** malloc_array2D(int row, int col);
void free_array2D(LNode **arr);
LNode** Translate_array(char** array, int row, int col); //将一个普通数组翻译为单链表节点的数组
LNode* find_start_LNode(LNode** Arr); //从数组中找到始点
LNode* find_end_LNode(LNode** Arr); //从数组中找到终点
LNode* pop_openList_minNode(LinkList L_OpenList); //返回开放列表中F值最小的节点
void push_openList_Node(LinkList L, LNode *elem); //插入一个节点并排序
bool insert_Into_CloseList(LNode* min_Open, LinkList L_CloseList);//插入OpenList中F值最小的节点到CloseList中去
int count_LNode_G(LNode* curLNode, LNode* aheadLNode); //计算节点的G值
int count_LNode_H(LNode* curLNode, LNode* endLNode); //计算节点的H值
int count_LNode_F(LNode* curLNode); //计算节点的F值
bool isExist_openList(LNode* curLNode); //查看节点是否在链表中，在返回ture,不在返回false
bool isExist_closeList(LNode* curLNode);
bool isobstacle(LNode* curLNode);
void check_around_curNode(LNode* cur, LNode* endLNode, LinkList open_list, LNode** Arr); //检查周围的节点，是否合适加入开放列表
char** load_maze(char* file_location);

int main(){
    char *  file_location=NULL;
    char ** array;
    file_location = (char*)malloc(sizeof(char)*50); //为文件路径字符串分配空间
    printf("Please input the file path of the maze:\n");
    scanf("%s",file_location);          //输入文件所在路径，绝对路径
    array = load_maze("e:/C++/source/maze.txt");
    LNode **maze = Translate_array(array, maze_row, maze_colum); //这里将数组的地图转为节点map的地图
    LinkList open_List = InitList(); //定义并初始化一个开放列表
    LinkList close_List = InitList(); //一个封闭列表
    LNode* endLNode = find_start_LNode(maze);   //逆向寻找通路，以便于回溯打印时方向正确
    LNode* startLNode = find_end_LNode(maze);
    LNode* curLNode = startLNode; //当前节点=开始节点
    curLNode->G = 0; //计算节点的三个值
    count_LNode_H(curLNode, endLNode);
    count_LNode_F(curLNode);
    push_openList_Node(open_List, curLNode); //先将开始节点插入开放列表
    while (1){
        if(curLNode->x == endLNode->x && curLNode->y == endLNode->y){
            break;
        }
        //LNode *e = NULL;
        curLNode = pop_openList_minNode(open_List);
        insert_Into_CloseList(curLNode, close_List);
        //2、查看起点周围的点是否在开放列表里，不在加入，在检测经过该点F值是否最小等；
        check_around_curNode(curLNode, endLNode, open_List, maze);
    }
    if(endLNode->path_next == NULL){
        printf("This maze has no track.\n");
        return 0;
    }
    printf("The track of the maze is:\n start-> (%d,%d)->",endLNode->x,endLNode->y);
    while (endLNode->path_next)
    {
        printf("(%d,%d)->", endLNode->path_next->x, endLNode->path_next->y);
        endLNode->path_next = endLNode->path_next->path_next;
    }
    printf("end");
    free(array);
    free_array2D(maze);
    system("pause");
    return 0;
}


LinkList InitList()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL)
    {
        printf("Defeat!");
        exit(1);
    }
    memset(L, 0, sizeof(LNode));
    return L;
}

LNode** malloc_array2D(int row, int col)
{
    LNode** map = (LNode**)malloc(row * sizeof(LNode*) + row * col * sizeof(LNode));
    LNode* head = (LNode*)(map + row);
    for ( i = 0; i < row; ++i)
         map[i] = head + i * col;
    return map;
}

LNode** Translate_array(char** array, int row, int colum)
{
    LNode **map = malloc_array2D(row, colum);
    for ( i = 0; i < row; ++i)
        for ( j = 0; j < colum; ++j)
        {
            (map[i] + j)->data = array[i][j];
            (map[i] + j)->G = 0;
            (map[i] + j)->H = 0;
            (map[i] + j)->F = 0; //(map[i] + j)->G + (map[i] + j)->H;
            (map[i] + j)->x = j;
            (map[i] + j)->y = i;
            (map[i] + j)->Close_flag = 0;
            (map[i] + j)->OPen_flag = 0;
            (map[i] + j)->next = NULL;
            (map[i] + j)->path_next = NULL;
        }
    return map;
}
void free_array2D(LNode **arr)
{
    free(arr);
}

//从数组中找到始点
LNode* find_start_LNode(LNode** Arr)
{
    LNode* start_LNode = NULL;
    int x,y;
    while(1){
        printf("start point(x,y):");
        scanf("%d,%d",&x,&y);
        if(x<0||y<0){
            printf("Input range error(0 ~ mazeSize-1),Please try again.\n");
            continue;
        }
        if((Arr[y]+x)->data!='1'){
            printf("Wrong start location!Please try again.\n");
            continue;
        }
        break;
    }
    start_LNode = (Arr[y]+x);
    //起点H=0,G=0,F=0
    start_LNode->G = 0;
    start_LNode->H = 0;
    start_LNode->F = 0; //起点，则默认所有值为0
    printf("Set OK\n");
    return start_LNode; //返回节点
    
}

//从数组中找到终点
LNode* find_end_LNode(LNode** Arr)
{
    LNode* end_LNode = NULL;
    int x,y;
    while(1){
        printf("end point(x,y):");
        scanf("%d,%d",&x,&y);
        if(x<0||y<0){
            printf("Input range error(0 ~ mazeSize-1),Please try again.\n");
            continue;
        }
        if((Arr[y]+x)->data!='1'){
            printf("Wrong end location!Please try again.\n");
            continue;
        }
        break;
    }
    end_LNode = (*(Arr + y) + x);
    end_LNode->F = 0;
    end_LNode->G = 0;
    end_LNode->H = 0;
    printf("Set OK\n");
    return end_LNode; //返回节点
}

 //计算节点的G值，移动代价消耗
int count_LNode_G(LNode* curLNode, LNode* aheadLNode){
    if (curLNode->x == aheadLNode->x && curLNode->y == aheadLNode->y)
        return 0;

    //斜方向G值为14，正方向G值为10
    if (aheadLNode->x - curLNode->x != 0 && aheadLNode->y - curLNode->y != 0)
        curLNode->G = aheadLNode->G + 14;
    else
        curLNode->G = aheadLNode->G + 10;
    return curLNode->G;
}

 //计算节点的H值，即该点到终点的距离
int count_LNode_H(LNode* curLNode, LNode* endLNode){
    //曼哈顿距离，乘上G
    curLNode->H = abs(endLNode->x - curLNode->x) * 10 + abs(endLNode->y - curLNode->y) * 10;
    return curLNode->H;
}

 //计算节点的F值，总代价
int count_LNode_F(LNode* curLNode)
{
    curLNode->F = curLNode->G + curLNode->H;
    return curLNode->F;
}

//按从小到大的顺序在openList中插入一个节点
void push_openList_Node(LinkList L, LNode *elem)
{
    LNode *p, *q;
    p = q = L;
    while (p->next != NULL && p->F < elem->F)
    {
        q = p;
        p = p->next;
    }
    if (p->F < elem->F)
        q = p;
    elem->next = q->next;
    q->next = elem;
    //插入成功，更改属性值OPen_flag = 1
    elem->OPen_flag = 1;
}

//返回开放列表中F值最小的节点
LNode* pop_openList_minNode(LinkList L_OpenList) {
    LNode *elem = NULL;
    if (L_OpenList->next) //为了安全，防止访问空指针
    {
        L_OpenList->next->OPen_flag = 0;
        elem = L_OpenList->next;
        L_OpenList->next = L_OpenList->next->next;
        elem->next = NULL;
    }
    else
        printf("Have a NULL point in pop_OpenList_mimNode().\n");
    return elem;
}

//插入OpenList中F值最小的节点到CloseList中去
bool insert_Into_CloseList(LNode* min_Open, LinkList L_CloseList){
    //对于CloseList中的节点并不需要排序,采用头插法
    min_Open->next = L_CloseList->next;
    L_CloseList->next = min_Open;
    min_Open->Close_flag = 1;
    return TURE;
}

//检测节点是否在openList中
bool isExist_openList(LNode* curLNode){
    return curLNode->OPen_flag;
}

//检测节点是否在closeList中
bool isExist_closeList(LNode* curLNode){
    return curLNode->Close_flag;
}

//检测是否为障碍
bool isobstacle(LNode* curLNode){
    if (curLNode->data == '0')
        return TURE;
    else
        return FALSE;
}

//该节点是否可以加入开放列表
bool CanJoinOpenList(LNode* cur){
    if (cur->x > -1 && cur->y > -1) //边界检测
    {
        if (!isExist_closeList(cur) && !isobstacle(cur)) //既不在关闭列表里，也不是障碍物
        {
            return TURE;
        }
        else
            return FALSE;
    }
    return FALSE;
}

void insert_open(LNode *Node, LNode* ahead, LNode* endLNode, LinkList open_list, LNode** Arr)
{
    if (!CanJoinOpenList(Node))
        return;

    if (isExist_openList(Node)){
        //经由ahead节点，会不会使得F的值更小
        if (Node->x - ahead->x != 0 && Node->y - ahead->y != 0)
        {
            //因为H值没有变化，所以直接比较F值即可
            if (Node->F > (ahead->F + 14))
            {
                count_LNode_G(Node, ahead);
                count_LNode_F(Node); //H值没有改变，所以还是原来的值
                Node->path_next = ahead; //也不用再插入
            }
        }
        else
        {
            if (Node->F > (ahead->F + 10))
            {
                count_LNode_G(Node, ahead);
                count_LNode_F(Node); //H值没有改变，所以还是原来的值
                Node->path_next = ahead; //也不用再插入
            }
        }
    }
    else 
    {
        //若没有加入openList，则直接加入
        count_LNode_G(Node, ahead);
        count_LNode_H(Node, endLNode);
        count_LNode_F(Node);
        Node->path_next = ahead;
        push_openList_Node(open_list, Node);
    }
}
void check_around_curNode(LNode* cur, LNode* endLNode, LinkList open_list, LNode** Arr)
{
    const int x = cur->x;
    const int y = cur->y;
    //检查边界，画图标记下已经检查的节点
    if (x + 1 < maze_row){
        insert_open(Arr[y] + x + 1, cur, endLNode, open_list, Arr);
        if (y + 1 < maze_colum)
            insert_open(Arr[y + 1] + x + 1, cur, endLNode, open_list, Arr);
        if(y - 1 >= 0)
            insert_open(Arr[y - 1] + x + 1, cur, endLNode, open_list, Arr);
    }
    if (y + 1 < maze_colum){
        insert_open(Arr[y + 1] + x, cur, endLNode, open_list, Arr);
        if(x - 1 >= 0)
            insert_open(Arr[y + 1] + x - 1, cur, endLNode, open_list, Arr);
    }
    if (x - 1 >= 0){
        insert_open(Arr[y] + x - 1, cur, endLNode, open_list, Arr);
        if (y - 1 >= 0)
            insert_open(Arr[y - 1] + x - 1, cur, endLNode, open_list, Arr);
    }

    if (y - 1 >= 0)
        insert_open(Arr[y - 1] + x, cur, endLNode, open_list, Arr);
}

char** load_maze(char* file_location){
    FILE *fp=NULL;
    char** maze;
    char** error;
    char tmp = 0;
    int flag = 0;
    if((fp = fopen(file_location,"r"))==NULL){
        perror("Faild to load maze");
        return error;
    }
    while(!feof(fp)){
        tmp = fgetc(fp);
        if(tmp == '\n'){
            ++maze_row;
            flag = 1;
        }
        if(tmp>=48&&tmp<=57&&flag == 0){
            ++maze_colum;
        }
    }
    rewind(fp);
    maze = (char **)malloc(sizeof(char*)*maze_row);
    for(i=0;i<maze_colum;i++){
        maze[i] = (char *)malloc(sizeof(char)*maze_colum);
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
    printf("maze colum:%d,maze_row:%d\n",maze_colum,maze_row);
    for(i=0;i<maze_row;i++){
        for(j=0;j<maze_colum;j++){
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
    printf("Finished loading.\n");
    fclose(fp);
    return maze;
}