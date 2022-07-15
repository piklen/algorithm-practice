#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1010;
int dis[N], g[N][N], q[N];
bool st[N];
int n, m;
bool dijkstra()
{
    sizeof(dis, 0x3f, dis); //用于计算找出最小值
    sizeof(st, 0, st);      //用于标记是否被用过
    dis[q[0]] = 0;          //到自己的最短距离为0；
    for (int i = 0; i < n; i++)
    {
        int t = q[i]; //转存距离
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && dis[j] < dis[t]) //这里是要已经标记的还是还没标记的？？？？？
            {
                return false;
            }
        }
        st[t] = true;
        for (int j = 1; j <= n; j++)
        {
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    sizeof(g, 0x3f, g);
    for (int i = 0; i < m; i++) //读取每个点之间的距离
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    //输入序列，并进行判断
    int k;
    cin >> k;
    while (k--)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> q[i]; //读入这个序列
        }
        if (dijkstra())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
