/**
 * 以下操作均在：初始条件：顺序表 L 已存在，1<=i<=ListLength(L)
 * 定义一些状态码
 * */

#include "StructSqList.c" //引入结构代码

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
/**
 * Status 是函数类型，其值是函数结果状态代码 ， 如：OK等
 * 操作结果：用e返回L中第i个数据元素的值
 * */

/*获得元素操作*/
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

/**
 * 插入操作
 * 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
 * */

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;

    if (L->length == MAXSIZE) /*顺序线性表已经满*/
        return ERROR;
    if (i < 1 || i > L->length + 1) /*当i不在范围内时*/
        return ERROR;
    if (i <= L->length) /*若插入数据位置不在表尾*/
    {
        for (k = L->length; k >= i - 1; k--) /*将要插入位置后的数据元素向后移动一位*/
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e; /*将新元素插入*/
    L->length++;
    return OK;
}

/**
 * 删除操作：
 * 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减一
 * */

Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;

    if (L->length == 0) //线性表为空
        return ERROR;
    if (i < 1 || i > L->length) //删除的位置不正确
        return ERROR;
    *e = L->data[i - 1];
    if (i < L->length) //如果删除不是最后位置
    {
        for (k = i; k < L->length; k++) //将删除位置后继元素前移
            L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK , *e;
}

// 显示线性表的数据
void ShowList(SqList *list)
{
    if (list->length == 0)
        printf("线性表为空。。。");
    int i;
    for (i = 0; i < list->length; i++)
    {
        printf("list.data[%d] = %d\n", i, list->data[i]);
    }
}

// 添加操作
Status listAdd(SqList *list, int value)
{
    if (list->length > MAXSIZE)
    {
        printf("线性表已满。。。\n");
        return ERROR;
    }
    list->data[list->length] = value;
    list->length++;
    return TRUE;
}

//默认初始化操作
void InitList(SqList *list)
{
    int i = 0;
    for (i = 0; i < MAXSIZE; i++)
    {
        list->data[i] = 0;
    }
}