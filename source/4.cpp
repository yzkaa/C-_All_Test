#ifndef _STACK_H_
#define _STACK_H_
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef char DataType;
 
//������ʽջ 
struct node{
    DataType element;  //����Ԫ�� 
	struct node *next; //ָ����һ������Ԫ�ص�ָ�� 
};

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
	s =new struct node;
	s->next = NULL;
	s->element =0;
	return s;
}

/*
   ��������push 
   �������ܣ���ջ��ѹ��һ������Ԫ��ֵΪx 
   ������������ѹջ������Ԫ�أ�ջͷ���ָ�� 
   ����ֵ����
*/
void push(DataType  x,Stack s) 
{
	//��ͷ��Ϊջ��
    PtrToNode temp ;
 	temp=new struct node;
 	temp->element = x;
 	temp->next = s->next;
 	s->next = temp;
}

/*
   ��������pop 
   �������ܣ�����ջ��Ԫ�ز�����Ԫ��ֵ 
   ����������ջͷ���ָ�� 
   ����ֵ��ջ��Ԫ�ص�ֵ 
*/
DataType pop(Stack s) 
{
	PtrToNode temp;
	int t;
	if(isEmpty(s)==0)
  	{
  		temp = s->next;
  		t = temp->element;
  		s->next = temp->next;
  		free(temp);
 		 return t;
 	}
}

DataType top(Stack s) 
{
	if(isEmpty(s)==0)
  	{
    	return s->next->element ;
  	}
}

/*
   ��������inToPost
   �������ܣ�����׺���ʽת��Ϊ��׺���ʽ��� 
   ������������׺���ʽ�������ַ������� 
   ����ֵ���� 
*/
void inToPost(char *expression)
{
   //�ڴ˴���д���룬�����׺���ʽת��Ϊ��׺���ʽ�����
   /**********  Begin  **********/
   int i=0;
   bool isNum=true;
   bool bracket=false;
   Stack str = createStack();
   while(expression[i]!=0){
	   if(isdigit(expression[i])){
		   
		   if(!isNum){
			   cout<<" ";
		   }		   
		   cout<<expression[i];
		   isNum=true;
	   }else{
		   
		   if(expression[i]==')'){
			   while(top(str)!='('){
				   isNum=false;
				   cout<<" "<<pop(str);
			   }
			   pop(str);
			   bracket=false;
		   }else if(expression[i]=='+'||expression[i]=='-'){
					if(top(str)=='*'||top(str)=='/'){
						while(isEmpty(str)==0){
							isNum=false;
							cout<<" "<<pop(str);   
						}
						push(expression[i],str);
					}
					else
					{
						push(expression[i],str);
					}
					
		   		}
			else {
				push(expression[i],str);
			}
		}
		i++;

	}
	while(isEmpty(str)==0){

		cout<<" "<<pop(str);
	}  
   /**********  End  **********/
}
#endif

//#include "stack_symbol.h"

int main(void)
{
	char express[80];
	cin>>express;
	inToPost(express);
}
