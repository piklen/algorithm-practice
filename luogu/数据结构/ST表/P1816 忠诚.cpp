#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int a[N], f[N][20];
void query(int l, int r)
{
    int k = log2(r - l + 1);
    printf("%d ", min(f[l][k], f[r - (1 << k) + 1][k]));
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query(l, r);
    }
    return 0;
}