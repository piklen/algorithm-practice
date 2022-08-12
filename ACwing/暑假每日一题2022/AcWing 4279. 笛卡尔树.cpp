#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N = 40;
int w[N];
vector<int> level[N];
int getmin(int l, int r)
{
    int res = l;
    for (int i = l; i <= r; i++)
    {
        if (w[i] < w[res])
        {
            res = i;
        }
    }
    return res;
}
void dfs(int l, int r, int d)
{
    if (l > r) //当区间内不存在数时，进行runturn，当l==r时，区间内存在一个数
    {
        return;
    }
    // int root = min_element(a+l,a+r);
    // int root_id = *min_element(a + l, a + r)-a;
    int root = getmin(l, r);     //找到l到r区间内的最小数的下标
    level[d].push_back(w[root]); //到这一层进行存储
    dfs(l, root - 1, d + 1);     // dfs左边
    dfs(root + 1, r, d + 1);     // dfs右边
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    dfs(0, n - 1, 0);
    for (int i = 0; level[i].size(); i++) //只要第i层存在，就进行操作
    {
        for (auto j : level[i]) //遍历第i层
        {
            cout << j << " ";
        }
    }
    return 0;
}
// dfs做法，直接遍历每一层，并且对每一层的数进行存储
// bfs做法，但是我不太理解
/*
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 40;

int n;
int w[N], L[N], R[N];
int q[N];

int getmin(int l, int r)
{
    int res = l;
    for (int i = l; i <= r; i++)
    {
        if (w[res] > w[i])
        {
            res = i;
        }
    }
    return res;
}

int dfs(int l, int r)
{
    if (l > r)
    {
        return -1;
    }
    int root = getmin(l, r);
    L[root] = dfs(l, root - 1);
    R[root] = dfs(root + 1, r);
    return root;
}

void bfs(int root)
{
    int hh = 0, tt = 0;
    q[0] = root;
    while (hh <= tt)
    {
        int t = q[hh++];
        cout << w[t] << ' ';
        if (L[t] != -1)

        {
            q[++tt] = L[t];
        }
        if (R[t] != -1)
        {
            q[++tt] = R[t];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int root = dfs(0, n - 1);
    bfs(root);

    return 0;
}
*/