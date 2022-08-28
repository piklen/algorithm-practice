#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N], tri1[N], tri2[N];
int n, m;
int lowbit(int x)
{
    return x & -x;
}
void add(int q[], int k, LL x)
{
    for (int i = x; i <= n; i += lowbit(x))
    {
        q[i] += x;
    }
}
LL sum(int q[], LL x)
{
    LL ans = 0;
    for (int i = x; i > 0; i -= lowbit(x))
    {
        ans += q[i];
    }
    return ans;
}
LL ssum(int x)
{
    return sum(tri1, x) * (x + 1) - sum(tri2, x);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        int b = a[i] - a[i - 1];
        add(tri1, i, b);
        add(tri2, i, (LL)b * i);
    }
    while (m--)
    {
        int s, l, r, k;
        scanf("%d", &s);
        if (s == 1)
        {
            scanf("%d%d%d", l, r, k);
            add(tri1, l, k);
            add(tri2, l, k * l);
            add(tri1, r + 1, -k);
            add(tri2, r + 1, -k * (r + 1));
        }
        else
        {
            scanf("%d%d", &l, &r);
            printf("%lld\n", ssum(r) - ssum(l - 1));
        }
    }
    return 0;
}