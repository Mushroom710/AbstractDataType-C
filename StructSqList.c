/**
 * �������Ա��˳��洢�ṹ����
 * */

#define MAXSIZE 5 //�洢�ռ��ʼ������

typedef int ElemType; //ElemType���͸���ʵ����������������� int

typedef struct sqList
{
    ElemType data[MAXSIZE - 1]; //����洢����Ԫ�أ����ֵΪMAXSIZE
    int length;             //���Ա�ǰ����
} SqList;