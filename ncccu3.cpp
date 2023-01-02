#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define ll long long
using namespace std;

const int N = 500010;

struct node
{
    int x, ans;
};

int n, m, k, r, p, x, y;
int in[N];
node tt;
queue<node> q;
vector<int> f[N];
int main()
{
    cin >> n >> k >> p;
    for (int i = 1; i <= p; i++) // 一边读入一边建图
    {
        cin >> x;
        q.push(node{x, 0});
        if (x == k) // 第一天就到了这个题
        {
            puts("0");
            return 0;
        }
    }
    cin >> r;
    for (int i = 1; i <= r; i++)
    {
        cin >> y >> m;
        in[y] = m;
        for (int i = 1; i <= m; i++)
        {
            cin >> x;
            f[x].push_back(y);
        }
    }
    while (!q.empty()) // 进行拓扑排序
    {
        tt = q.front();
        tt.ans++; // 全局的递增的答案
        q.pop();
        for (int i = 0; i < f[tt.x].size(); i++)
        {
            in[f[tt.x][i]]--;
            if (!in[f[tt.x][i]]) // 如果需要的题目都做完了就可以入队了
            {
                if (f[tt.x][i] == k) // 判断是否为第 k 道题目
                {
                    printf("%d\n", tt.ans);
                    return 0;
                }
                q.push(node{f[tt.x][i], tt.ans});
            }
        }
    }
    puts("-1"); // 排完了还是没有输出就直接输出 - 1。
    return 0;
}