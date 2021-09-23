/**
 * 这是单链表的存储结构
 * 
 * */

typedef int ElemType;

typedef struct LNode
{
    ElemType data; //数据域

    struct LNode *next; //指针域

} LNode, *LinkList; //LinkList为指向结构体LNode的指针类型