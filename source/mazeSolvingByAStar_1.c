#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#define TURE 1
#define FALSE 0
int i,j;
int maze_row=0;            //��ͼ������
int maze_colum=0;          //��ͼ������
typedef struct LNode {
    char data;                   //��Ӧ�����е���ֵ
    int F;                      //F = G + H;
    int G;                      //G������� A �ƶ���ָ��������ƶ����ۣ����ŵ���÷�������ɵ�·��
    int H;                      //H����ָ���ķ����ƶ����յ� B �Ĺ���ɱ�
    int x, y;                   //��Ӧ�����е�����
    bool OPen_flag;             //�ڿ����б���Ϊ1������Ϊ0
    bool Close_flag;            //�ڹر��б���Ϊ1������Ϊ0
    struct LNode* next;         //������������
    struct LNode* path_next;    //���������ҵ���·��
}LNode, *LinkList;

LinkList InitList(); //����һ����ʼ��������
LNode** malloc_array2D(int row, int col);
void free_array2D(LNode **arr);
LNode** Translate_array(char** array, int row, int col); //��һ����ͨ���鷭��Ϊ������ڵ������
LNode* find_start_LNode(LNode** Arr); //���������ҵ�ʼ��
LNode* find_end_LNode(LNode** Arr); //���������ҵ��յ�
LNode* pop_openList_minNode(LinkList L_OpenList); //���ؿ����б���Fֵ��С�Ľڵ�
void push_openList_Node(LinkList L, LNode *elem); //����һ���ڵ㲢����
bool insert_Into_CloseList(LNode* min_Open, LinkList L_CloseList);//����OpenList��Fֵ��С�Ľڵ㵽CloseList��ȥ
int count_LNode_G(LNode* curLNode, LNode* aheadLNode); //����ڵ��Gֵ
int count_LNode_H(LNode* curLNode, LNode* endLNode); //����ڵ��Hֵ
int count_LNode_F(LNode* curLNode); //����ڵ��Fֵ
bool isExist_openList(LNode* curLNode); //�鿴�ڵ��Ƿ��������У��ڷ���ture,���ڷ���false
bool isExist_closeList(LNode* curLNode);
bool isobstacle(LNode* curLNode);
void check_around_curNode(LNode* cur, LNode* endLNode, LinkList open_list, LNode** Arr); //�����Χ�Ľڵ㣬�Ƿ���ʼ��뿪���б�
char** load_maze(char* file_location);

int main(){
    char *  file_location=NULL;
    char ** array;
    file_location = (char*)malloc(sizeof(char)*50); //Ϊ�ļ�·���ַ�������ռ�
    printf("Please input the file path of the maze:\n");
    scanf("%s",file_location);          //�����ļ�����·��������·��
    array = load_maze("e:/C++/source/maze.txt");
    LNode **maze = Translate_array(array, maze_row, maze_colum); //���ｫ����ĵ�ͼתΪ�ڵ�map�ĵ�ͼ
    LinkList open_List = InitList(); //���岢��ʼ��һ�������б�
    LinkList close_List = InitList(); //һ������б�
    LNode* endLNode = find_start_LNode(maze);   //����Ѱ��ͨ·���Ա��ڻ��ݴ�ӡʱ������ȷ
    LNode* startLNode = find_end_LNode(maze);
    LNode* curLNode = startLNode; //��ǰ�ڵ�=��ʼ�ڵ�
    curLNode->G = 0; //����ڵ������ֵ
    count_LNode_H(curLNode, endLNode);
    count_LNode_F(curLNode);
    push_openList_Node(open_List, curLNode); //�Ƚ���ʼ�ڵ���뿪���б�
    while (1){
        if(curLNode->x == endLNode->x && curLNode->y == endLNode->y){
            break;
        }
        //LNode *e = NULL;
        curLNode = pop_openList_minNode(open_List);
        insert_Into_CloseList(curLNode, close_List);
        //2���鿴�����Χ�ĵ��Ƿ��ڿ����б�����ڼ��룬�ڼ�⾭���õ�Fֵ�Ƿ���С�ȣ�
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

//���������ҵ�ʼ��
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
    //���H=0,G=0,F=0
    start_LNode->G = 0;
    start_LNode->H = 0;
    start_LNode->F = 0; //��㣬��Ĭ������ֵΪ0
    printf("Set OK\n");
    return start_LNode; //���ؽڵ�
    
}

//���������ҵ��յ�
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
    return end_LNode; //���ؽڵ�
}

 //����ڵ��Gֵ���ƶ���������
int count_LNode_G(LNode* curLNode, LNode* aheadLNode){
    if (curLNode->x == aheadLNode->x && curLNode->y == aheadLNode->y)
        return 0;

    //б����GֵΪ14��������GֵΪ10
    if (aheadLNode->x - curLNode->x != 0 && aheadLNode->y - curLNode->y != 0)
        curLNode->G = aheadLNode->G + 14;
    else
        curLNode->G = aheadLNode->G + 10;
    return curLNode->G;
}

 //����ڵ��Hֵ�����õ㵽�յ�ľ���
int count_LNode_H(LNode* curLNode, LNode* endLNode){
    //�����پ��룬����G
    curLNode->H = abs(endLNode->x - curLNode->x) * 10 + abs(endLNode->y - curLNode->y) * 10;
    return curLNode->H;
}

 //����ڵ��Fֵ���ܴ���
int count_LNode_F(LNode* curLNode)
{
    curLNode->F = curLNode->G + curLNode->H;
    return curLNode->F;
}

//����С�����˳����openList�в���һ���ڵ�
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
    //����ɹ�����������ֵOPen_flag = 1
    elem->OPen_flag = 1;
}

//���ؿ����б���Fֵ��С�Ľڵ�
LNode* pop_openList_minNode(LinkList L_OpenList) {
    LNode *elem = NULL;
    if (L_OpenList->next) //Ϊ�˰�ȫ����ֹ���ʿ�ָ��
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

//����OpenList��Fֵ��С�Ľڵ㵽CloseList��ȥ
bool insert_Into_CloseList(LNode* min_Open, LinkList L_CloseList){
    //����CloseList�еĽڵ㲢����Ҫ����,����ͷ�巨
    min_Open->next = L_CloseList->next;
    L_CloseList->next = min_Open;
    min_Open->Close_flag = 1;
    return TURE;
}

//���ڵ��Ƿ���openList��
bool isExist_openList(LNode* curLNode){
    return curLNode->OPen_flag;
}

//���ڵ��Ƿ���closeList��
bool isExist_closeList(LNode* curLNode){
    return curLNode->Close_flag;
}

//����Ƿ�Ϊ�ϰ�
bool isobstacle(LNode* curLNode){
    if (curLNode->data == '0')
        return TURE;
    else
        return FALSE;
}

//�ýڵ��Ƿ���Լ��뿪���б�
bool CanJoinOpenList(LNode* cur){
    if (cur->x > -1 && cur->y > -1) //�߽���
    {
        if (!isExist_closeList(cur) && !isobstacle(cur)) //�Ȳ��ڹر��б��Ҳ�����ϰ���
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
        //����ahead�ڵ㣬�᲻��ʹ��F��ֵ��С
        if (Node->x - ahead->x != 0 && Node->y - ahead->y != 0)
        {
            //��ΪHֵû�б仯������ֱ�ӱȽ�Fֵ����
            if (Node->F > (ahead->F + 14))
            {
                count_LNode_G(Node, ahead);
                count_LNode_F(Node); //Hֵû�иı䣬���Ի���ԭ����ֵ
                Node->path_next = ahead; //Ҳ�����ٲ���
            }
        }
        else
        {
            if (Node->F > (ahead->F + 10))
            {
                count_LNode_G(Node, ahead);
                count_LNode_F(Node); //Hֵû�иı䣬���Ի���ԭ����ֵ
                Node->path_next = ahead; //Ҳ�����ٲ���
            }
        }
    }
    else 
    {
        //��û�м���openList����ֱ�Ӽ���
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
    //���߽磬��ͼ������Ѿ����Ľڵ�
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