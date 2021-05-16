#include"linkList.h"
#include<iostream>

LinkList::LinkList(){
    head = new Node;
    head->next = NULL;
    head->data = 0;
}

LinkList::~LinkList(){
    delete head;
}


// int main (){
//     LinkList list;
//     std::cout<<list.head->data;
//     return 0;
// }