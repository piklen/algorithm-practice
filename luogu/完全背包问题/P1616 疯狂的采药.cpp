#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10110;
const int M = 1e7 + 100;
int v[N];
int t[N];
long long f[M];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = t[i]; j <= m; j++)
        {
            f[j] = max(f[j], f[j - t[i]] + v[i]);
            // f[i][j]=max(f[i-1][j],f[i][j-t[i]]+v[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
// 1.这个是完全背包问题，其关键是与01背包问题选择的可能性不一样，它看的是选不停数量的v[i]作出的集合
// 2.关于这个题，不开long long 会爆int