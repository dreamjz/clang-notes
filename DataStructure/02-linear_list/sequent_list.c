#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LIST_INCREMENT 10  // 线性表存储空间分配增量

typedef enum
{
    OK,
    ERROR,
    OVERFLOW
} Status;

typedef int IntElement;

typedef struct {
    IntElement *elem; // 存储空间基址
    int length;       // 当前长度
    int size;         // 当前分配的存储容量（以 sizeof(IntElement) 为单位）
} SqList;

SqList initList_Sq() {
    SqList l;
    l.elem = (IntElement *)malloc(LIST_INIT_SIZE * sizeof(IntElement));
    if(! l.elem) {
        exit(OVERFLOW);
    }
    l.length = 0;
    l.size = LIST_INIT_SIZE;
    return l;
}

Status listInsert_Sq(SqList l, int pos, IntElement e) {
    if(pos < 1 || pos > l.length + 1) {
        return ERROR;
    }
    if(l.length >= l.size) {
        IntElement *newBase;
        newBase = (IntElement *)realloc(l.elem, (l.size + LIST_INCREMENT) * sizeof(IntElement));
        if(! newBase) {
            exit(OVERFLOW);
        }
        l.elem = newBase;
        l.size += LIST_INCREMENT;
    }
    IntElement *q = &l.elem[pos - 1];
    for (IntElement *p = &l.elem[l.length - 1]; p > q; p--) {
        *(p + 1) = *p;
    }
    *q = e;
    l.length++;
    return OK;
}

void printSqList(SqList l) {
    printf("Print sq_list ...\n");
    for (int i = 0; i < l.length; i++)
    {
        printf("%d,", l.elem[i]);
    }
    printf("done\n");
    return;
}

int main() {
    printf("Start ...\n");
    SqList l = initList_Sq();

    for (int i = 0; i < 10; i++) {
        l.elem[i] = i;
    }
    l.length = 10;

    printSqList(l);
    printf("End ...\n");
}