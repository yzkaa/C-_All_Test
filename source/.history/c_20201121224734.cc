#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char DataType;
 

//队列数据元素结构
typedef struct node
{
    DataType info;
    struct node *next;
}QueueData;

typedef struct queueRecord
{
    QueueData  *front, *rear ;
 }LINKQUEUE;
typedef struct queueRecord *PLinkQueue;

PLinkQueue createEmptyQueue_link( )
{
   //创建一个空队列，实质：生成一个LINKQUEUE类型的结点，并给front �? rear 成员赋�?
    //请在此处填写代码，完成相应功�?
    /*-------begin----------*/
    PLinkQueue plqu;
    plqu=(PLinkQueue)malloc(sizeof(struct queueRecord));
    if(plqu!=NULL)
    {
        plqu->front=NULL;
        plqu->rear=NULL;
    }
    else
    {
        printf("Out of space!\n");
    }
    return plqu;
    /*-------end----------*/
    
}

int isEmptyQueue_link(PLinkQueue  queue)
{ //判定队列是否为空，实质： 看队列的front指针是否为空，若为空，则队列为空
    
  //请在此处填写代码，完成相应功�?
    /*-------begin----------*/
    if(queue->front==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
    /*-------end----------*/
}

 void enQueue_link(DataType x, PLinkQueue queue)
 {
   //将数据元素x插入队尾。实质：生成一个struct node类型的结点，并给相应成员赋值后插入队尾
    //请在此处填写代码，完成相应功�?
    /*-------begin----------*/
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("Out of space!\n");
    }
    else
    {
        p->info=x;
        p->next=NULL;
        if(queue->front==NULL)
        {
            queue->front=p;
        }
        else
        {
            queue->rear->next=p;
        }
        queue->rear=p;
    }
    
    /*-------end----------*/
 }

void enQueue_link(QueueData *p,PLinkQueue Q)
 {
  //本函数的功能是将 struct node 类型的结点插入队尾，与enQueue_link(DataType x, PLinkQueue queue)的区别是，不需要生成结�?
  
     //请在此处填写代码，完成相应功�?
    /*-------begin----------*/
    p=(struct node *)malloc(sizeof(struct node));
    if(p==NULL)
    {
        printf("Out of space!\n");
    }
    else
    {
        p->next=NULL;
        if(Q->front==NULL)
        {
            Q->front=p;
        }
        else
        {
            Q->rear->next=p;
        }
        Q->rear=p;
    }
    
    
    /*-------end----------*/
   
 }

DataType deQueue_link(PLinkQueue Q)
 {
     //出队，实质： 取出Q队列的队首结点，返回该结点的数据元素，并将该结点使用enQueue_link(QueueData *p,PLinkQueue Q)插入队尾
     //本函数为针对本实验特殊设计，可实现秘钥的循环使用
     //请在此处填写代码，完成相应功�?
    /*-------begin----------*/
    struct node *head=Q->front;
    Q->front=Q->front->next;
    enQueue_link(head,Q);
    return head->info;
    
    /*-------end----------*/
     
 }
 
 void decrypt(char src[], char key[], char dest[])
 {
 	/*  参数�? src 放的是源�? �? key 放的是秘�? �? dest 放加密后的密�?
       加密函数�? 步骤提示
       1. 初始化一个空队列Q
       2. 将key数组的元素逐个插入队列Q
       3. 逐个访问src数组的源文，并加密， 使用deQueue_link(Q)函数可得到队首秘钥，并使秘钥循环使用
    */
     PLinkQueue Q=createEmptyQueue_link();
     int i=0;
     for(i=0;key[i]!=0;i++){
         enQueue_link(key[i],Q);
     }
     for( i=0;src[i]!=0;i++){
         dest[i]=src[i]+deQueue_link(Q);
     }
     dest[i]='\0';
 }
 
 int main(void)
 {
 	char src[80] , key[20], dest[80];
  
    cin>>src ;
    
 	cin>>key;
 	decrypt(src , key , dest);
    cout<<dest;  
 }

