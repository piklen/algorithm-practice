#include <stdio.h>
#include <malloc.h>
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2
#define OVERFLOW -2
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1

typedef int ElemType;
typedef int Status;
typedef struct
{
    int *elem;
    int length;
    int listsize;
} SqList;

int InitList(SqList *L)
{
    (*L).elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!(*L).elem)
    {
        exit(OVERFLOW);
    }
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return OK;
}
void ListInsert(SqList *L, int i, ElemType e)
{
    ElemType *newbase, *q, *p;
    if (i < 1 || i > (*L).length + 1)
    {
        return;
    }
    if ((*L).length >= (*L).listsize)
    {
        newbase = (ElemType *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
    q = (*L).elem + i - 1;
    for (p = (*L).elem + (*L).length - 1; p >= q; --p)
    {
        *(p + 1) = *p;
    }
    *q = e;
    ++(*L).length;
    return;
}

int main()
{
    SqList L;
    ElemType e, e0;
    Status i;
    int j, k;
    i = InitList(&L);
    printf("请输入一个数进行八进制转换：\n");
    int xlenth = 0;
    for (j = 1; j <= 1; j++)
    {
        int x;
        scanf("%d", &x);
        int temp = x;
        while (temp)
        {
            int aa, bb;
            xlenth++;
            aa = temp % 8;
            ListInsert(&L, xlenth, aa);
            temp /= 8;
        }
    }
    for (j = xlenth; j >= 1; j--)
    {
        printf("%d", *(L.elem + j - 1));
    }
    printf("\n");
    return 0;
}