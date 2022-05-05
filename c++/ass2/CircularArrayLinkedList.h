#include "TemporaryEmployee.h"
struct nodetype {
    TemporaryEmployee info;
    int next;
};
class CircularArrayLinkedList {
public:
    static const int MAX_ARRAYSIZE=20;
    struct nodetype Array[MAX_ARRAYSIZE];
    int top;
    int avail;
    CircularArrayLinkedList();
    void add(TemporaryEmployee &t);
    void del(TemporaryEmployee &t);
    int getnode();
    void freenode(int p);
};