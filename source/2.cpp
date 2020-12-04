#ifndef _LINKSET_H_
#define _LINKSET_H_
#include <iostream>
using namespace std;
typedef int DataType;

struct  node
{
    DataType  element;
    struct node  *next;
};
typedef struct node * SET;
void insert(DataType datax, SET set);

/*
  �������� InitSet
  �������ܣ����ݲ���num����ʼ������
  ��������������Ԫ�صĸ���
  ����ֵ������ͷָ��
*/
SET InitSet(int num)
{

    SET p;
    p = new struct  node  ;
    p->next = NULL;
    p->element = num;
    int temp;
    for(int i =0;i<num;i++)
    {
        cin>>temp;
        insert(temp, p); //����insert���������������ݲ��뼯��
    }
    return p;
}


/*
  �������� find
  �������ܣ��ڼ����в���ֵΪdatax�ĳ�Ա
  ����������datax:�����ҵ�ֵ �� set�����ϵ�ͷ���?
  ����ֵ���ҵ�ֵΪdatax�ĳ�Ա����1�����򷵻�0
*/
int find(DataType datax, SET  set)
{
    //���ڴ˴���д���룬��set�����в���ֵΪdatax�ĳ�Ա�����ҵ�����1�����򷵻�0
    /**********  Begin  **********/
    SET p = set->next;
    while(p!=NULL){
      if(p->element==datax){
        return 1;
      }
      p=p->next;
    }
    return 0;
    /**********   End   **********/
}

/*
  �������� insert
  �������ܣ��ڼ���set�в���ֵΪdatax�ĳ�Ա ������λ���ڱ�ͷ
  ����������datax:��������? �� set�����ϵ�ͷ���?
  ����ֵ����
*/
void insert(DataType datax, SET set)
{
    //���ڴ˴���д���룬��datax���뼯��set�� ע���򼯺�Ԫ��������ģ�ֻ�轫�³�Ա�����ͷ
    /**********  Begin  **********/
    SET p = new node;
    p->element = datax;
    p->next=set->next;
    set->next=p;
    /**********   End   **********/
 }

/*
  �������� copyList
  �������ܣ�������setA�������ɼ���setB
  ����������setA ��setB��ͷ���?
  ����ֵ����
*/
void copySet(SET setA, SET setB)
{
    //���ڴ˴���д���룬ʵ�ֽ�����setA�ĳ�Ա���Ƶ�����setB�Ĺ���
    /**********  Begin  **********/
    setB->element += setA->element;
    SET B=setB;
    while(B->next!=NULL){
      B=B->next; 
    }
    B->next=setA->next;
    /**********   End   **********/
}

/*
  �������� printSet
  �������ܣ�������ϵ�Ԫ�أ��Կո���ΪԪ��֮��ֽ��?
  ����������set��ͷ���?
  ����ֵ����
*/
void printSet(SET set)
{
    //���ڴ˴���д���룬ʵ���������Ԫ�صĹ��ܣ�Ԫ��֮���Կո�Ϊ�ֽ��
    /**********  Begin  **********/
  SET p=set->next;
  while(p!=NULL){
    cout<<" ";
    cout << p->element;
    p = p->next;
  }
  cout<<"ok";

    /**********  End  **********/
}

/*
  �������� setUnion
  �������ܣ�����������setA �� setB�Ĳ���
  ����������setA��setB��ͷ���?
  ����ֵ���������ϵ�ͷ���?
*/
SET setUnion(SET setA ,SET setB)
{
    //���ڴ˴���д���룬��ֱ��ʹ�������Ѿ�ʵ�ֵĸ�����
    /**********  Begin  **********/
    SET unionSet = new node;
    SET A = setA->next;
    SET B = setB;
    SET U = unionSet;
    unionSet->next = NULL;
    while (A!=NULL){
        if(find(A->element,B)==0){
          insert(A->element, U);
          U = U->next;
        }       
        A = A->next;
    }
    U->next = B->next;

    return unionSet;

    /**********  End  **********/
}

/*
  �������� setIntersect
  �������ܣ�����������setA �� setB�Ľ���
  ����������setA��setB��ͷ���?
  ����ֵ���������ϵ�ͷ���?
*/
SET setIntersect(SET setA ,SET setB)
{
    //���ڴ˴���д���룬��ֱ��ʹ�������Ѿ�ʵ�ֵĸ�����
    /**********  Begin  **********/
    SET A = setA->next;
    SET B = setB;
    SET intersectSet = new node;
    intersectSet->next = NULL;
    while(A!=NULL){
        if(find(A->element,B)==1){
          insert(A->element, intersectSet);
        }
        A=A->next;
    }
    return intersectSet;

    /**********  End  **********/
}

/*
  �������� setExcept
  �������ܣ�����������setA �� setB�Ĳ�
  ����������setA��setB��ͷ���?
  ����ֵ��������ϵ�ͷ���
*/
SET setExcept(SET setA ,SET setB)
{
    //���ڴ˴���д���룬��ֱ��ʹ�������Ѿ�ʵ�ֵĸ�����
    /**********  Begin  **********/
    SET B = setB;
    SET exceptSet = new node;
    SET E = exceptSet;
    SET IntersectSet = setIntersect(setA,setB);
    exceptSet->next = NULL;
    copySet(setA, setB);
    B=B->next;
    while(B!=NULL){
      if(find(B->element,IntersectSet)==0){
        insert(B->element, E);
        E=E->next;
      }
      B=B->next;
    }
    return exceptSet;
    /**********  End  **********/
}

#endif
//#include "linkset.h"

int main(void)
{
	int count;
	cin>>count;
	SET setA = InitSet(count);
	cin>>count;
	SET setB = InitSet(count);
	cout<<"\nunion:";
  printSet(setUnion(setA,setB));
  cout<<"\nIN:";
	printSet(setIntersect(setA,setB)); 
	cout<<"\nEX:";
	printSet(setExcept(setA,setB));

}
