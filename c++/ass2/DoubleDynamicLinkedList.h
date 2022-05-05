#include "PermanentEmployee.h"
struct node
{
    PermanentEmployee data;
    struct node *prev;
    struct node *next;
};
class DoubleDynamicLinkedList {
public:
    node *head,*tail;
    DoubleDynamicLinkedList();
    void add_node(PermanentEmployee &p);
};