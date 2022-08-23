#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 310;
int en[N];
int nx[N], head[N];
int w[N], f[N][N];
int idx = 0;
int n, m;
//邻接表的构建
void add(int a, int b) // 添加一条边a->b
{
    en[idx] = b;
    nx[idx] = head[a];
    head[a] = idx++;
}
void dfs(int u)
{
    for (int i = head[u]; i != -1; i = nx[i]) //遍历以u为节点的所有子树
    {
        int j = en[i]; //找到邻接表的下一个点
        dfs(j);
        {
            for (int k = m; k >= 0; k--)
            {
                for (int be = 1; be <= k; be++)
                {
                    f[u][k] = max(f[u][k], f[u][k - be] + f[j][be]); //子树状态转移
                }
            }
        }
    }
    for (int i = m; i >= 1; i--)
    {
        f[u][i] = f[u][i - 1] + w[u]; //将自身权重加上
    }
}

int main()
{
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a >> w[i];
        add(a, i);
    }
    m++; //因为把0当成了一个结点，起权值为0;
    dfs(0);
    cout << f[0][m] << endl;
    return 0;
}
//其实自己感觉这个树状Dp很难，超级难，因为自己对数据结构的一些知识不熟悉，包括构建邻接表来存储边什么的