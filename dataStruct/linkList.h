#ifndef LINKLIST_H
#define LINKLIST_H
typedef int DataType;

class Node
{
public:
	DataType data;
	Node *next;
};

class LinkList
{
private:
    /* data */
public:
    LinkList(); //构造一个空链表,默认data为0
    ~LinkList();

    // void createLinkList(int size); //构造一个长度为size的链表
    // void clearLinkList(); //清空链表
    // int listLength();   //返回链表长度


    Node *head;
};

#endif