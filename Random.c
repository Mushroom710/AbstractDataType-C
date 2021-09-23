#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/**
 * 随机数
 * */ 

void main(){
    int a;
    srand((unsigned)time(0));
    a = rand() % 100;
    printf("%d\n",a);
    int i;
    for (i = 0; i < 5;i++)
    {
        printf("%d\n",rand()%100);
    }
}