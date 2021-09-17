/**
 * 这是一个测试文件
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
    /*默认初始化*/
    InitList(list);
    /*c语言没有默认初始值，需要事先指定好初始值！！！*/
    list->length = 0;
    // 写一个菜单
    printf("请选择：\n1.添加 \n2.删除 \n3.显示 \n");
    while (TRUE)
    {
        if(flag)
        {
            printf("退出程序...");
            break;
        }
        scanf("%c", &key);
        switch (key)
        {
            case '1':
                printf("请输入待添加的值：");
                scanf("%d", &value);
                loop = listAdd(list, value);
                break;
            case '2':
                printf("请输入要删除的索引：");
                scanf("%d",&index);
                loop , elem = ListDelete(list,index,&elem);
                printf("你删除了索引为%d，值为%d\n", index, elem);
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