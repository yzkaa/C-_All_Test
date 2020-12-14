#include<stdio.h>
#include<stdlib.h>
/*************************************Stack begin***************************************/
//����һ���Թ�λ�õ��������ͣ���Ҫ�������
typedef struct{
    int x,y;
}dataType; 

//һ�����
struct node{
    dataType location;
	struct node *next; //ָ����һ������Ԫ�ص�ָ�� 
};

//��ʽջ
typedef struct node *PtrToNode;
typedef PtrToNode Stack;

/*
   ��������isEmpty 
   �������ܣ��ж�ջ�Ƿ�Ϊ�� 
   ����������ջͷ���ָ�� 
   ����ֵ����ջΪ�գ��򷵻�1�����򷵻�0
*/
int isEmpty(Stack s) 
{
    return  s->next ==NULL;
}
/*
   ��������createStack 
   �������ܣ�����һ����ջ��ʵ����ֻ��Ҫ��ʼ��ջͷ��� 
   ������������ 
   ����ֵ��ջͷ���ָ�� 
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
   ��������push 
   �������ܣ���ջ��ѹ��һ������Ԫ��ֵΪx 
   ������������ѹջ������Ԫ�أ�ջͷ���ָ�� 
   ����ֵ����
*/
void push(dataType coordinate,Stack s) 
{
	//��ͷ��Ϊջ��
    PtrToNode temp ;
 	temp=(PtrToNode)malloc(sizeof(struct node));
 	temp->location.x = coordinate.x;
    temp->location.y = coordinate.y;
 	temp->next = s->next;
 	s->next = temp;
}

/*
   ��������pop 
   �������ܣ�����ջ��Ԫ�ز�����Ԫ��ֵ 
   ����������ջͷ���ָ�� 
   ����ֵ������ֵ 
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
int set_OK = 0;            //һ��flag�����ڼ�������յ��Ƿ�ɹ����á�
int maze_row=9;            //��ͼ������
int maze_colum=9;          //��ͼ������
int i=0,j=0;               //ѭ������
char** load_maze(char*);   //�����ͼ�ļ�
void set_startP_and_endP(char** , dataType* , dataType*);   //���������յ�
void depth_first_search(Stack ,char **,dataType,dataType);  //���Թ���ʹ����������㷨
int side_way_num(char ** ,dataType );                       //�жϲ�·����

/****************************************main****************************************/
int main(){
    char *  file_location=NULL;         //����һ���ļ�·���ַ���
    char ** maze;                       //��ά�ַ����飬������ͼ
    dataType start;                     //һ�����
    dataType end;                       //һ���յ�
    start.x = start.y = end.x = end.y = -1;     //�������յ������ʼ��Ϊ-1
    Stack track = NULL;                 //·��ջ
    track = createStack();              //����һ��ջ�ռ�
    file_location = (char*)malloc(sizeof(char)*50); //Ϊ�ļ�·���ַ�������ռ�
    printf("Please input the file path of the maze(9x9):\n");
    scanf("%s",file_location);          //�����ļ�����·��������·��
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

    //ȷ���������
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

    //ȷ���յ�����
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

//ʹ��ջ�����Թ����������������ȱ���
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
        //����˳��������� ��������
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
    //���ҽ���̽��
    if(location.x+1<maze_colum){
        if(maze[location.y][location.x+1] == '1'){
            ++sideWay;  
        }
    }

    //�������̽��
    if(location.x-1>=0){
        if( maze[location.y][location.x-1] == '1'){
            ++sideWay;
        }
    }

    //���Ͻ���̽��
    if(location.y-1>=0){
        if( maze[location.y-1][location.x] == '1'){
            ++sideWay;
        }
    }

    //���½���̽��
    if(location.y+1<maze_row){
        if( maze[location.y+1][location.x] == '1'){
            ++sideWay;
        }
    }
    printf("sideWay:%d\n",sideWay);
    return sideWay;
}