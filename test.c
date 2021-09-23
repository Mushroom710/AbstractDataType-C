#include "stdio.h"
#include "Methods.c"

LinkList L;

void main(){
    // L = (LinkList)malloc(sizeof(LNode));
    // L->next = NULL;
    L = InitList(L);
    CreateList_H(L, 5);
    ShowList(L);
    L = ReverseLinkList(L);
    ShowReverse(L);
}