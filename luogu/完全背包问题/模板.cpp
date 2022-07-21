#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e4 + 10;
int v[N], w[N];
int f[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = v[i]; j <= m; j++) //剩下的空间必须大于当前所需空间
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}