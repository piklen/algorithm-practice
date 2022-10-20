#include <iostream>
using namespace std;
//结构体链表初始化
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//链表初始化，头结点指向空
void InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LinkList));
    L->next = NULL;
}

//头插法建立单链表
LinkList HeadInsert(LinkList &L)
{
    InitList(L);
    int x;
    cin >> x;
    while (x != 0)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next; //使插入的这个结点的next指向头结点的next
        L->next = s;       //头结点的next指向插入的这个结点
        cin >> x;
    }
    return L; //将这个构建出的链表进行返回
}

//尾插法建立单链表
LinkList TailInsert(LinkList &L)
{
    InitList(L);
    LNode *s, *r = L;
    int x;
    cin >> x;
    while (x != 0)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s; //上一个结点的next指向当前结点
        r = s;       //转移最后一个结点的位置
        cin >> x;
    }
    r->next = NULL; //尾结点的next指针指向空结点
    return L;
}

//遍历链表
void PrintList(LinkList L)
{
    LNode *p = L->next;
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}

//计算链表长度
int Lenth(LinkList L)
{
    LNode *p = L->next;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

//查找，以结点的形式来进行查找
//按值查找，在链表中查找是否有这个值
LNode *LocateElem(LinkList L, int x)
{
    LNode *p = L->next;
    while (p && p->data != x)
    {
        p = p->next;
    }
    return p;
}

//按位查找，查找在链表中的第几位
LNode *GetElem(LinkList L, int i)
{
    int j = 1;
    LNode *p = L->next;
    if (i == 0)
    {
        return L;
    }
    if (i < 1)
    {
        return NULL;
    }
    while (j < i && p)
    {
        p = p->next;
        j++;
    }
    return p;
}

//将x插入到链表中第i个位置上
void Insert(LinkList L, int i, int x)
{
    LNode *p = GetElem(L, i - 1);
    LNode *s = (LNode *)malloc(sizeof(LNode)); //创造一个空的结点
    s->data = x;                               //结点的data指向插入的那个值
    s->next = p->next;                         //指针指向之前p的next指向的值
    p->next = s;                               // p链接起s来
}

//删除操作，删除单链表中第i个结点
void Delete(LinkList &L, int i)
{
    if (i < 1 || i > Lenth(L))
    {
        cout << "delete failed: index is wrong" << endl;
    }
    LNode *p = GetElem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}
//链表判空
bool EmptyList(LinkList L)
{
    if (L->next)
    {
        return false;
    }
    else
    {
        return false;
    }
}

//清空链表
void ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
}
int main()
{
    cout << "使用尾插法创建链表，以输入0结束\n";
    LinkList L = TailInsert(L);
    cout << "输出链表\n";
    PrintList(L);
    cout << "以头插法创建链表，以输入0结束" << endl;
    LinkList LL = HeadInsert(LL);
    cout << "输出链表\n";
    PrintList(LL);
    cout << "第一个链表的长度为：" << Lenth(L) << endl;
    cout << "请输入要删除第几位数:" << endl;
    int x;
    cin >> x;
    Delete(L, x);
    cout << "输出链表\n";
    PrintList(L);
    cout << "第一个链表的长度为：" << Lenth(L) << endl;
    int a, b;
    cout << "请输入在第几个位置添加xx" << endl;
    cin >> a >> b;
    Insert(L, a, b);
    cout << "输出链表\n";
    PrintList(L);
    cout << "第一个链表的长度为：" << Lenth(L) << endl;
    return 0;
}