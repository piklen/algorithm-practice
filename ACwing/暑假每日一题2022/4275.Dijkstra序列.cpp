#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010;
int dis[N], g[N][N], q[N];
bool st[N];
int n, m;
bool dijkstra()
{
    memset(dis, 0x3f, sizeof dis); //用于计算找出最小值
    memset(st, 0, sizeof st);      //用于标记是否被用过
    dis[q[0]] = 0;                 //到自己的最短距离为0；
    for (int i = 0; i < n; i++)    //进行遍历这个dijkstra序列
    {
        int t = q[i]; //转存距离
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && dis[j] < dis[t]) //这里是要已经标记的还是还没标记的？？？？？，用没有标记的表示这个数据还没有被选上
            {
                return false; //如果出现更小的，显然不符合题意，所以returnFALSE
            }
        }
        st[t] = true;
        for (int j = 1; j <= n; j++)
        {
            dis[j] = min(dis[j], dis[t] + g[t][j]); //算法最重要的点，进行数据更新，找到J点到源点的最小值
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) //读取每个点之间的距离
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c; //无向图进行间距存储
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
/*
1.dijsktra 算法是求单源路径最短的一种求法，首先要理解题目，就是这个序列的第一个就是目标源，然后进行排列，第二个是离目标源最近的一个点，第三个是离目标源次近的点
2.它的时间复杂度要进行注意，这种最朴素的做法时间复杂度为O(N^2+M)
3.自己犯错在把memset写成了sizeof(a,0,a)这种形式，导致半天找不出错误在哪，所以可以给自己一个提示，那就是当算法思路没有问题时，很有可能是自己在某个函数上写错了

*/