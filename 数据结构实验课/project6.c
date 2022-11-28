#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define INFINITY 0
#define MAX_VERTEX_NUM 20 //最大顶点数
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} Graphkind;
#define MAX_EDGE_NUM 40 //最大边数
#define True 1;
#define False 0;
int visited[MAX_VERTEX_NUM];

typedef int VertexType; //顶点数据类型

typedef struct ArcNode
{
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
} ALGraph;

void CreateDG(ALGraph &G)
{
    int i, j, k;
    ArcNode *p;
    printf("创建一个无向图:");
    printf("顶点数:");
    scanf("%d", G.vexnum);
    printf("边数:");
    scanf("%d", G.arcnum);
    for (i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data = i;
        G.vertices[i].firstarc = NULL;
    }
    for (k = 0; k < G.arcnum; k++)
    {
        printf("请输入第%d条边:", k + 1);
        scanf("%d,%d", &i, &j);
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p;
    }
}

void Disp(ALGraph G)
{
    int i, j;
    ArcNode *p;
    printf("输出图为:");
    for (i = 0; i < G.vexnum; i++)
    {
        p = G.vertices[i].firstarc;
        j = 0;
        while (p != NULL)
        {
            printf("(%d,%d)\n", i, p->adjvex);
            p = p->nextarc;
            j = 1;
        }
        // if (j == 1)
    }
}

void dfs(ALGraph G, int v) //深度优先遍历
{
    ArcNode *p;
    printf("%d\n", v);
    visited[v] = 1;
    p = G.vertices[v].firstarc;
    while (p != NULL)
    {
        if (!visited[p->adjvex])
            dfs(G, p->adjvex);
        p = p->nextarc;
    }
}

void dfs1(ALGraph G)
{
    int i;
    for (i = 0; i < G.vexnum; i++)
        if (visited[i] == 0)
            dfs(G, i);
}
typedef struct ArcCell
{
    int adj; //无权图，1或0表示相邻否；带权图则是权值。
    // int *info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
    VertexType vexs[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix arcs;                  //邻接矩阵
    int vexnum, arcnum;              //图的当前顶点数和弧数。
    Graphkind kind;
} MGraph;
int LocateVex(MGraph MG, VertexType v1)
{
    int i;
    for (i = 0; i < MG.vexnum; i++)
        if (MG.vexs[i] == v1)
            return i;
    return -1;
}

int CreatUDN(MGraph &MG)
// 采用数组表示法，构造有向向网 G
{
    VertexType v1, v2;
    int j, i;
    printf("利用邻接矩阵创建有向网：\n");
    printf("输入图的顶点数:");
    scanf("%d\n", MG.vexnum);
    printf("输入图的弧数:");
    scanf("%d\n", MG.arcnum);
    printf("请依次输入顶点向量:");
    for (int i = 0; i < MG.vexnum; i++)
    {
        scanf("%d\n", MG.vexs[i]);
    }
    for (int i = 0; i < MG.vexnum; i++)
        for (j = 0; j < MG.vexnum; j++)
        {
            MG.arcs[i][j].adj = INFINITY;
        }
    printf("输入边依附的两个顶点\n");
    for (int k = 0; k < MG.arcnum; ++k) //构造邻接矩阵
    {
        scanf("%d,%d\n", v1, v2);
        i = LocateVex(MG, v1);
        j = LocateVex(MG, v2);
        MG.arcs[i][j].adj = 1;
        MG.arcs[j][i].adj = MG.arcs[i][j].adj;
    }
    return 1;
}

void dispMGraph(MGraph MG)
{
    printf("图的邻接矩阵图是:\n");
    for (int i = 0; i < MG.vexnum; i++)
    {
        for (int j = 0; j < MG.vexnum; j++)
            printf(" %d  ", MG.arcs[i][j].adj);
        printf("\n");
    }
}
void DepthFirstSearch(MGraph MG, int v)
{
    int vj;

    visited[v] = True;
    int n = MAX_VERTEX_NUM;
    for (vj = 0; vj < n; vj++)
        if (!visited[vj] && MG.arcs[v][vj].adj == -1)
            DepthFirstSearch(MG, v);
}
int main()
{
    int i;
    printf("\n\n----------------------------------------------------------------------------\n\n");
    printf("* * * *欢迎使用本程序！本程序将用深度搜索和广度搜索进行无向图的遍历。* * * *\n\n");
    printf("----------------------------------------------------------------------------\n");
found:
    std::cout << "请选择：1：邻接表。2：邻接矩阵。3：结束操作" << std::endl;
    printf("请输入：i=");
    scanf("%d", &i);
    switch (i)
    {
    case (1):
        ALGraph G;
        CreateDG(G);
        Disp(G);
        int v;
        printf("选择：1.深度优先遍历,2.广度优先遍历.\n");

        int n;
    found1:
        printf("输入n:");
        scanf("%d\n", &n);
        switch (n)
        {
        case (1):
            printf("输入顶点:");
            scanf("%d\n", &v);
            printf("深度优先序列:");
            Disp(G);
            dfs1(G);
            goto found;
        case (2):
            break;
        }

        goto found;
        break;
    case (2):
        MGraph MG;
        CreatUDN(MG);
        dispMGraph(MG);
        printf("选择：1.深度优先遍历,2.广度优先遍历.\n");

        int b;
        printf("输入b:");
        scanf("%d\n", &b);
        switch (b)
        {
        case (1):
            printf("深度优先序列:");
            DepthFirstSearch(MG, v);
            goto found;
        case (2):
            break;
        }

        goto found;
        break;
    case 3:
        printf("\n\n\n\n");
        printf("----------------------------------\n\n");
        printf("* * * *谢谢使用！欢迎指正！* * * *\n\n");
        printf("----------------------------------\n\n");
        printf("\n\n\n\n");
        break;
    }
    return 0;
}