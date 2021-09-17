/**
 * ���²������ڣ���ʼ������˳��� L �Ѵ��ڣ�1<=i<=ListLength(L)
 * ����һЩ״̬��
 * */

#include "StructSqList.c" //����ṹ����

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
/**
 * Status �Ǻ������ͣ���ֵ�Ǻ������״̬���� �� �磺OK��
 * �����������e����L�е�i������Ԫ�ص�ֵ
 * */

/*���Ԫ�ز���*/
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
 * �������
 * �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
 * */

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;

    if (L->length == MAXSIZE) /*˳�����Ա��Ѿ���*/
        return ERROR;
    if (i < 1 || i > L->length + 1) /*��i���ڷ�Χ��ʱ*/
        return ERROR;
    if (i <= L->length) /*����������λ�ò��ڱ�β*/
    {
        for (k = L->length; k >= i - 1; k--) /*��Ҫ����λ�ú������Ԫ������ƶ�һλ*/
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e; /*����Ԫ�ز���*/
    L->length++;
    return OK;
}

/**
 * ɾ��������
 * ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�һ
 * */

Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;

    if (L->length == 0) //���Ա�Ϊ��
        return ERROR;
    if (i < 1 || i > L->length) //ɾ����λ�ò���ȷ
        return ERROR;
    *e = L->data[i - 1];
    if (i < L->length) //���ɾ���������λ��
    {
        for (k = i; k < L->length; k++) //��ɾ��λ�ú��Ԫ��ǰ��
            L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK , *e;
}

// ��ʾ���Ա������
void ShowList(SqList *list)
{
    if (list->length == 0)
        printf("���Ա�Ϊ�ա�����");
    int i;
    for (i = 0; i < list->length; i++)
    {
        printf("list.data[%d] = %d\n", i, list->data[i]);
    }
}

// ��Ӳ���
Status listAdd(SqList *list, int value)
{
    if (list->length > MAXSIZE)
    {
        printf("���Ա�����������\n");
        return ERROR;
    }
    list->data[list->length] = value;
    list->length++;
    return TRUE;
}

//Ĭ�ϳ�ʼ������
void InitList(SqList *list)
{
    int i = 0;
    for (i = 0; i < MAXSIZE; i++)
    {
        list->data[i] = 0;
    }
}