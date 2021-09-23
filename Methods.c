/**
 * 以下操作均在有头结点的单链表中执行
 * 
 * 定义一些状态码
 * 
 * 在 C 中：非零为真，零为假
 * */

#include "StructLinkList.c"
#include "stdlib.h"
#include "stdio.h"

#define TRUE 1
#define OK 1
#define FALSE 0
#define ERROR 0
// #define NULL 0

/**
 * Status 是函数类型，其值是函数结果状态代码 ， 如：OK等
 * 操作结果：用e返回L中第i个数据元素的值
 * */
typedef int Status;

//构造一个空的单链表
//初始化一个带有头结点的链表
//初始化完成应返回头指针
LinkList InitList(LinkList L)
{
    L = (LinkList)malloc(sizeof(LNode));
    L->data = 65535;
    L->next = NULL;
    return L;
}
/**
 * 清空一个单链表
 * 操作结果：
 * 清除链表中的数据，并释放资源
*/
void ClearLinkList(LinkList L){
    LinkList p = L->next;//保留头结点
    LinkList temp = NULL;
    L->next = NULL;//头结点的next域置为空
    while (p)
    {
        temp = p->next;
        free(p);
        p = temp;
    }
    printf("清除成功。。。\n");
}

/**
 * 单链表取值
 * 操作结果：
 * 根据序号 i 获取元素的值，用 e 返回 L 中第 i 个数据元素的值
 * 注：传过来的链表可能有头结点，也可能没有头结点，注意区分
 * 这里默认头结点的数据是一个不可能的值即 ：65535
*/
Status GetElem(LinkList L, int i, ElemType *e)
{
    if(L->data == 65535){
        LinkList p = L->next; //初始化 p 指向首元结点，即第一个有数据的元素
        int j = 1;            //计数器初始化为 1
        while (p && j < i)
        {                //遍历链表，直到p为空或p指向第i个元素
            p = p->next; //指向下一个结点
            j++;         //计数器加一
        }
        if (!p || j > i)
        { //i的值不合法，i>n或i<=0
            return ERROR;
        }
        *e = p->data; //取得第i个结点的数据
        return OK;
    }
    LinkList p = L; //初始化 p 指向首元结点，即第一个有数据的元素
    int j = 1;            //计数器初始化为 1
    while (p && j < i)
    {                //遍历链表，直到p为空或p指向第i个元素
        p = p->next; //指向下一个结点
        j++;         //计数器加一
    }
    if (!p || j > i)
    { //i的值不合法，i>n或i<=0
        return ERROR;
    }
    *e = p->data; //取得第i个结点的数据
    return OK;
}

/**
 * 单链表按值查找
 * 操作结果：
 * 根据参数 e 找到对应的元素 
 * 注：传过来的链表可能有头结点，也可能没有头结点，注意区分
 * 这里默认头结点的数据是一个不可能的值即 ：65535
*/

//返回一个LNode结构体指针类型，即获取到 e 所在的结点地址
LNode *LocateElem(LinkList L, ElemType e)
{
    if(L->data == 65535){//有头结点
        LinkList p = L->next; //初始化 p 指向首元结点
        while (p && p->data != e)
        { // 遍历
            p = p->next;
        }
        return p; //找到则返回值为e的结点地址p，查找失败p为NULL
    }
    //没有头结点
    LinkList p = L->next; //初始化 p 指向首元结点
    while (p && p->data != e)
    { // 遍历
        p = p->next;
    }
    return p; //找到则返回值为e的结点地址p，查找失败p为NULL
}

/**
 * 单链表的插入
 * 操作结果：
 * 在对应位置插入元素，成功返回OK，失败返回ERROR
*/
//传入链表，插入位置，插入的数据
Status ListInsert(LinkList L, int i, ElemType e)
{
    //先找到插入的位置的前一个位置
    LinkList p = L;
    int j = 0;
    while (p && (j < i - 1))
    {
        p = p->next;
        j++;
    }
    if (!p || (j > i - 1))
    { //插入位置不正确
        return ERROR;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); //初始化一个结点，用于插入数据
    s->data = e;
    // 常规的插入操作
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * 单链表的删除
 * 操作结果：
 * 删除相应位置的结点，并释放其占有的资源
*/
//删除的下标
Status ListDelete(LinkList L, int i)
{
    LinkList p = L;
    int j = 0;
    if (L->data == 65535)
    { //有头结点
        //找到待删除的结点的前一个结点
        while ((p->next) && (j < i - 1))
        {
            p = p->next;
            j++;
        }
    }
    else
    {
        p = L;
        //找到待删除的结点的前一个结点
        while (p && (j < i - 1))
        {
            p = p->next;
            j++;
        }
    }
    if (!(p->next) || (j > i - 1))
    { //删除的位置不合理
        return ERROR;
    }
    LinkList q = p->next; //初始化一个临时结点，用于保存位置，以便待会释放资源
    //这里应该打印提示信息，是否删除
    printf("你删除了数据为：%d\n",q->data);
    p->next = q->next;
    free(q); //释放资源
    return OK;
}

/**
 * 创建一个单链表
 * 头插法也称前插法
 * 操作结果：
 * 得到一个逆序的单链表
 * */
//传入一个单链表L,需要多长n
void CreateList_H(LinkList L, int n)
{
    //如果先调用初始化InitList函数，这两步就是冗余的
    // L = (LinkList)malloc(sizeof(LNode));
    // L->next = NULL;
    int i;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        printf("第%d个元素的值是：",i+1);
        scanf("%d", &p->data);
        printf("\n");
        p->next = L->next; //将新的结点插入到头结点之后
        L->next = p;
    }
}

/**
 * 后插法
 * 操作结果：
 * 得到一个正序的单链表
*/
//传入一个单链表L,需要多长n
void CreateList_R(LinkList L, int n)
{
    //如果先调用初始化InitList函数，这两步就是冗余的
    // L = (LNode *)malloc(sizeof(LNode));
    // L->next = NULL;
    LinkList r = L; //初始化时 尾指针指向头结点
    int i;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        printf("第%d个元素的值是：", i + 1);
        scanf("%d", &p->data);
        printf("\n");
        p->next = NULL; //将新节点插入尾结点之后
        r->next = p;
        r = p; //r指向新的尾结点p
    }
}

/**
 * 显示链表
 * 操作结果：
 * 在控制台打印出链表的数据
*/
void ShowList(LinkList L)
{
    if (L==NULL || L->next == NULL)
    {
        printf("链表为空。。。\n");
        return;
    }
    LinkList p = L->next;
    int i = 1;
    while (p)
    {
        printf("序号：%d\t\t数据：%d\n",i, p->data);
        p = p->next;
        i += 1;
    }
    printf("\n");
}

void ShowReverse(LinkList L){
    LinkList p = L;
    int i = 1;
    while (p)
    {
        printf("序号：%d\t\t数据：%d\n", i, p->data);
        p = p->next;
        i += 1;
    }
    printf("\n");
}

/**
 * 反转链表, 迭代法
 * 操作结果：
 * 链表反转
 * */ 

LinkList ReverseLinkList(LinkList L){
    // if(L == NULL|| L->next == NULL){
    //     return L;
    // }
    LinkList pre = NULL;
    if (L->data == 65535)
    { //有头结点
        LinkList cur = L->next;
        while (cur)
        {
            LinkList next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
    else
    { //没有头结点
        LinkList cur = L;
        while (cur)
        {
            LinkList next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
    return pre;
}

/**
 * 默认初始化有 5 个数据的链表
 * 操作结果：
 * 初始化一个有5个结点的链表
*/

void DefaultInit(LinkList L){
    LinkList r = L; //初始化时 尾指针指向头结点
    int i;
    int a;//随机数
    srand((unsigned)time(0));
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        p->data = rand() % 100;//随机生成一到一百的随机数   
        p->next = NULL; //将新节点插入尾结点之后
        r->next = p;
        r = p; //r指向新的尾结点p
    }
}
