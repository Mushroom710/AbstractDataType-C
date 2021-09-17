/**
 * 这是线性表的顺序存储结构代码
 * */

#define MAXSIZE 5 //存储空间初始分配量

typedef int ElemType; //ElemType类型根据实际情况而定，这里用 int

typedef struct sqList
{
    ElemType data[MAXSIZE - 1]; //数组存储数据元素，最大值为MAXSIZE
    int length;             //线性表当前长度
} SqList;