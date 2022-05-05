#include "DoubleDynamicLinkedList.h"
#include "PermanentEmployee.h"
DoubleDynamicLinkedList::DoubleDynamicLinkedList()
{
    head = nullptr;
    tail = nullptr;
}
void DoubleDynamicLinkedList::add_node(PermanentEmployee &p){
    node *tmp = new node;
    tmp->data = p;
    tmp->next = nullptr;
    if(head == nullptr){
        head = tmp;
        tail = tmp;
        tmp->prev= nullptr;
    }
    else{
        tmp->prev=tail;
        tail->next = tmp;
        tail = tail->next;
    }
}