#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/*创建二叉树*/
void create(BiTree *T)
{
    char c;
    scanf("%c", &c);
    if (c != '#')
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = c;
        create(&((*T)->lchild));
        create(&((*T)->rchild));
    }
    else
        *T = NULL;
}
/*按层遍历*/
void Traverse(BiTree T)
{
    BiTree Queue[20];
    BiTree p;
    int front = 0, rear = 0;
    if (T)
    {
        p = T;
        Queue[rear] = p;
        rear = (rear + 1) % 20;
        while (front != rear)
        {
            p = Queue[front];
            printf("%c", p->data);
            front = (front + 1) % 20;
            if (p->lchild)
            {
                Queue[rear] = p->lchild;
                rear = (rear + 1) % 20;
            }
            if (p->rchild)
            {
                Queue[rear] = p->rchild;
                rear = (rear + 1) % 20;
            }
        }
    }
}
int main()
{
    BiTree T;
    create(&T);
    Traverse(T);
    return 0;
}