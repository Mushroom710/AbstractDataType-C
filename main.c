#include "stdio.h"
#include "Methods.c"

// LNode L;         //定义一个全局变量,废弃
LinkList L;         //装X写法
Status loop = FALSE; //定义一个标记
Status err;
int len;
int e;//全局变量 e 用于存储结点数据
int i;//用于记录下标位置

void ShowMenu()
{
    //写一个菜单
    printf("请选择：1.默认初始化一个链表\n");
    printf("\t2.取出一个值\n");
    printf("\t3.按值查找\n");
    printf("\t4.插入一个元素，输入插入的位置\n");
    printf("\t5.删除一个元素，输入删除的位置\n");
    printf("\t6.正序创建一个单链表，输入要创建一个多长的链表\n");
    printf("\t7.反序创建一个单链表，输入要创建一个多长的链表\n");
    printf("\t9.显示链表...\n");
    printf("\t10.反转链表...\n");
    printf("\t11.清空链表...\n");
    printf("\tdefault.输入其他数退出程序。。\n");
}

void main()
{
    L = InitList(L);
    DefaultInit(L);
    printf("默认初始化完成，有5个数据！\n");
    // if (err)
    // {
    //     printf("链表初始化成功！！！\n");
    // }else{
    //     printf("初始化失败。。");
    //     return;
    // }
    ShowMenu();
    int key;
    scanf("%d", &key);
    for (;;)
    {
        switch (key)
        {
        case 1:
            DefaultInit(L);
            printf("默认初始化成功！！！\n");
            break;
        case 2:
            printf("你想取出哪个位置的数据？");
            scanf("%d", &i);
            int flag = GetElem(L, i, &e);
            if (flag)
            {
                printf("你成功取到了一个数据：%d \n", e);
            }
            else
            {
                printf("太可惜了，一个数据都没有，快去填几个数据去。。\n");
            }
            break;
        case 3:
            printf("想查找哪个数据的位置？：");
            int index;
            scanf("%d", &index);
            LinkList result = LocateElem(L, index);
            if(result == 0){
                printf("没找到。。。\n");
                break;
            }
            printf("找到啦！\n");
            printf("地址是：%p\n", result);
            printf("数据是：%d\n",result->data);
            printf("\n");
            break;
        case 4:
            printf("插入一个元素...\n");
            printf("插入到哪个位置：");
            scanf("%d",&i);
            while(TRUE)
            {
                printf("填入什么数据：");
                scanf("%d",&e);
                if(e % e == 0){
                    break;
                }else{
                    printf("哎呀。填错数据了。。\n");
                }
            }
            loop = ListInsert(L, i, e);
            if(loop){
                printf("插入成功！\n");
            }else{
                printf("插入的位置不正确...\n");
            }
            loop = FALSE;
            break;
        case 5:
            printf("删除一个元素...\n");
            printf("要删除元素的下标位置：");
            scanf("%d", &i);
            err = ListDelete(L, i);
            if(err){
                printf("删除成功！\n");
            }else{
                printf("删除位置不合理！\n");
            }
            break;
        case 6:
            printf("正序创建一个链表。。。\n");
            printf("创建多长的链表：");
            scanf("%d", &len);
            CreateList_R(L, len);
            break;
        case 7:
            printf("反序创建一个链表。。。\n");
            printf("创建多长的链表：");
            scanf("%d", &len);
            CreateList_H(L, len);
            break;
        case 9:
            printf("显示的结果是：\n");
            ShowList(L);
            break;
        case 10:
            printf("反转链表：\n");
            L = ReverseLinkList(L);
            ShowReverse(L);
            break;
        case 11:
            printf("清空链表：\n");
            ClearLinkList(L);
            break;
        default:
            printf("退出程序.....");
            loop = TRUE;
            break;
        }
        if (loop)
        {
            break;
        }
        ShowMenu();
        scanf("%d", &key);
    }
}