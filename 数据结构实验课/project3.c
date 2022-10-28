#include <stdio.h>
#include <malloc.h>

#define OVERFLOW -2
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
/* 定义ElemType为int类型 */
typedef int ElemType;
typedef int Status;
typedef struct LNode /* 单链表的结点类型 */
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

void InitList(LinkList *L);                          /* 初始化单链表 */
void DestroyList(LinkList *L);                       /* 销毁单链表 */
void ClearList(LinkList L);                          /* 清空单链表 */
Status ListEmpty(LinkList L);                        /* 检查单链表是否为空 */
void ListTraverse(LinkList L, void (*vi)(ElemType)); /* 遍历单链表 */
int ListLength(LinkList L);                          /* 求单链表的长度 */
Status GetElem(LinkList L, int i, ElemType *e);      /* 从单链表表中查找元素 */
/* 从单链表表中查找与给定元素值相同的元素在链表中的位置 */
int LocateElem(LinkList L, ElemType e);
Status ListInsert(LinkList L, int i, ElemType e); /* 向单链表中插入元素 */
Status ListDelete(LinkList L, int i, ElemType e); /* 从单链表中删除元素 */

void InitList(LinkList *L)
{                                                /* 操作结果：構造一个空的線性表L */
    *L = (LinkList)malloc(sizeof(struct LNode)); /* 產生头结點，並使L指向此头结點 */
    if (!*L)                                     /* 存儲分配失敗 */
        exit(OVERFLOW);
    (*L)->next = NULL; /* 指针域為空 */
}

void DestroyList(LinkList *L)
{ /* 初始條件：線性表L已存在。操作结果：销毁線性表L */
    LinkList q;
    while (*L)
    {
        q = (*L)->next;
        free(*L);
        *L = q;
    }
}
void ClearList(LinkList L) /* 不改变L */
{                          /* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
    LinkList p, q;
    p = L->next; /* p指向第一个结点 */
    while (p)    /* 没到表尾 */
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL; /* 头结点指针域为空 */
}

Status ListEmpty(LinkList L)
{                /* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
    if (L->next) /* 非空 */
        return FALSE;
    else
        return TRUE;
}
int ListLength(LinkList L)
{ /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
    int i = 0;
    LinkList p = L->next; /* p指向第一个结点 */
    while (p)             /* 没到表尾 */
    {
        i++;
        p = p->next;
    }
    return i;
}
Status GetElem(LinkList L, int i, ElemType *e) /* 算法2.8 */
{                                              /* L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR */
    int j = 1;                                 /* j为计数器 */
    LinkList p = L->next;                      /* p指向第一个结点 */
    while (p && j < i)                         /* 顺指针向后查找，直到p指向第i个元素或p为空 */
    {
        p = p->next;
        j++;
    }
    if (!p || j > i) /* 第i个元素不存在 */
        return ERROR;
    *e = p->data; /* 取第i个元素 */
    return OK;
}

int LocateElem(LinkList L, ElemType e)
{ /* 初始条件: 线性表L已存在 */
    /* 操作结果: 返回L中第1个与e相等的数据元素的位序。 */
    /*           若这样的数据元素不存在，则返回值为0 */
    LinkList p = L->next;
    int j = 1;
    while (p->data != e && p->next)
    {
        p = p->next;
        j++;
    }
    if (j <= ListLength(L))
    {
        return ERROR;
    }
    else
    {
        return j;
    }
}
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{ /* 初始条件: 线性表L已存在 */
    /* 操作结果: 若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱， */
    /*           返回OK；否则操作失败，pre_e无定义，返回INFEASIBLE */
    LinkList q, p = L->next; /* p指向第一个结点 */
    while (p->next)          /* p所指结点有后继 */
    {
        q = p->next; /* q为p的后继 */
        if (q->data == cur_e)
        {
            *pre_e = p->data;
            return OK;
        }
        p = q; /* p向后移 */
    }
    return INFEASIBLE;
}
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{ /* 初始条件：线性表L已存在 */
    /* 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继， */
    /*           返回OK;否则操作失败，next_e无定义，返回INFEASIBLE */
    LinkList p = L->next; /* p指向第一个结点 */
    while (p->next)       /* p所指结点有后继 */
    {
        if (p->data == cur_e)
        {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}
Status ListInsert(LinkList L, int i, ElemType e) /* 算法2.9。不改变L */
{                                                /* 在带头结点的单链线性表L中第i个位置之前插入元素e */
    int j = 0;
    LinkList p = L, s;
    while (p && j < i - 1) /* 寻找第i-1个结点 */
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;                           /* i小于1或者大于表长 */
    s = (LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
    s->data = e;                                /* 插入L中 */
    s->next = p->next;
    p->next = s;
    return OK;
}
Status ListDelete(LinkList L, int i, ElemType e) /* 算法2.10。不改变L */
{                                                /* 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值 */
    int j = 0;
    LinkList p = L, q;
    while (p->next && j < i - 1) /* 寻找第i个结点，并令p指向其前岖 */
    {
        p = p->next;
        j++;
    }
    if (!p->next || j > i - 1) /* 删除位置不合理 */
        return ERROR;
    q = p->next; /* 删除并释放结点 */
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}
void ListTraverse(LinkList L, void (*vi)(ElemType))
/* vi的形参类型为ElemType */
{ /* 初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi() */
    LinkList p = L->next;
    while (p)
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

LNode *Build_Node() /* 头插法建立带头结点的单链表 */
{
    LNode *head, *p;
    int x;
    head = (LNode *)malloc(sizeof(LNode));
    ;
    head->next = NULL;
    printf("输入各结点的值,以0结束:");
    while (EOF != (scanf("%d", &x)) && x != 0)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->data = x;
        p->next = head->next;
        head->next = p;
    }
    return head;
}

void Print_Node(LinkList L) /* 打印单链表 */
{
    LinkList p = L->next;
    while (p)
    {
        printf("%d", p->data);
        p = p->next;
    };
    printf("\n");
}
int Count_Node(LNode *head)
{
    LNode *p = head->next;
    int num = 0;
    while (p != NULL)
    {
        num++;
        p = p->next;
    }
    return num;
}

main()
{
    int *a; /*用a来存储单链表中的第n个元素*/
    int b;  /*用b来存储删除单链表中的第n个元素*/
    int c;  /*用来存储单链表长度*/
    int *d; /*用来存储前驱*/
    int *f; /*用来存储后继*/
    int g;  /*用来存储所找元素的位置*/
    int i, m, n;
    LinkList La;
    InitList(&La); /*初始化单链表La*/
    printf("***************************链表演示程序********************\n");
    printf("请输入链表结点数： ");
    scanf("%d", &m);
    printf("请输入用来建立链表的数:\n");
    i = 1;
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &n);
        ListInsert(La, i, n);
    }
    printf("**********************您建立的链表为：");
    Print_Node(La);
    printf("**********************判断此链表是否非空：");
    if (ListEmpty(La))
        printf("空!\n");
    else
        printf("非空!+长度为%d\n", ListLength(La));
    printf("*********************请输入你要在链表中取元素的位置：");
    scanf("%d", &n);
    GetElem(La, n, a); /*取单链表中第n个元素并用a存储*/
    printf("你要取的第%d个元素a=%d\n", n, *a);
    Print_Node(La);
    ListDelete(La, 3, b); /*删除单链表中第三个元素并用b存储*/
    Print_Node(La);
    ListInsert(La, 4, 9); /*在第4个元素前插入9*/
    Print_Node(La);
    c = ListLength(La); /*求单链表长度*/
    printf("*********************请输入你要求前驱的元素的值：");
    scanf("%d", &n);
    PriorElem(La, n, d); /*求n的前驱*/
    printf("元素%d的前缀为%d\n", n, *d);
    printf("*********************请输入你要求后继的元素的值：");
    scanf("%d", &n);
    NextElem(La, n, f); /*求n的后继*/
    printf("元素%d的后继为%d\n", n, *f);
    g = LocateElem(La, 4); /*定位操作*/
    printf("g=%d\n", g);
    // printf("b=%d\n", *b);
    return 0;
}