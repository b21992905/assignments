#include "CircularArrayLinkedList.h"
CircularArrayLinkedList::CircularArrayLinkedList() {
    for(int i=0; i<19;i++){
        Array[i].next=i+1;
    }
    Array[19].next=0;
    top=-1;
}
int CircularArrayLinkedList::getnode() {
    int p;
    p = avail;
    avail = Array[avail].next;
    return p;
}
void CircularArrayLinkedList::freenode(int p)
{
    Array[p].next = avail;
    avail = p;
    return;
}

void CircularArrayLinkedList::add(TemporaryEmployee &t) {
    int p=getnode();
    Array[p]=t;
    top=p;
    Array[p].next=avail;

}

void CircularArrayLinkedList::del(TemporaryEmployee &t) {
    freenode(p);
}