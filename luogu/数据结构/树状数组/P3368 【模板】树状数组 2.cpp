#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
int n, m;
int a[N];
LL ans[N];
int lowbit(int x)
{
    return x & -x;
}
void add(int k, int x)
{
    for (int i = k; i <= n; i += lowbit(i))
    {
        ans[i] += x;
    }
}
LL sum(int x)
{
    LL res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        res += ans[i];
    }
    return res;
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
        add(i, a[i] - a[i - 1]);
    }
    while (m--)
    {
        LL k, l, r, x;
        cin >> k;
        if (k == 1)
        {
            scanf("%d%d%d", &l, &r, &x);
            add(l, x);
            add(r + 1, -x);
        }
        else
        {
            scanf("%d", &l);
            printf("%lld\n", sum(l));
        }
    }
    return 0;
}