/**
 * ����һ�������ļ�
 * */

#include "stdio.h"
#include "Methods.c"
#include "malloc.h"

void main()
{
    SqList *list;
    int i, value , index , elem;
    Status flag = FALSE;
    Status loop;
    char key;
    list = (SqList *)malloc(sizeof(SqList));
    /*Ĭ�ϳ�ʼ��*/
    InitList(list);
    /*c����û��Ĭ�ϳ�ʼֵ����Ҫ����ָ���ó�ʼֵ������*/
    list->length = 0;
    // дһ���˵�
    printf("��ѡ��\n1.��� \n2.ɾ�� \n3.��ʾ \n");
    while (TRUE)
    {
        if(flag)
        {
            printf("�˳�����...");
            break;
        }
        scanf("%c", &key);
        switch (key)
        {
            case '1':
                printf("���������ӵ�ֵ��");
                scanf("%d", &value);
                loop = listAdd(list, value);
                break;
            case '2':
                printf("������Ҫɾ����������");
                scanf("%d",&index);
                loop , elem = ListDelete(list,index,&elem);
                printf("��ɾ��������Ϊ%d��ֵΪ%d\n", index, elem);
                break;
            case '3':
                ShowList(list);
                break;
            case 'e':
                flag = TRUE;
                break;
        }
    }
}