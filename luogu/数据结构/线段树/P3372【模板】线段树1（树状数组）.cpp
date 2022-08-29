#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n, m;
int a[N];
LL tr[N], tri[N];
// tr[]数组是原始数组的差分数组d[i]的树状数组
// tri[]数组是原始数组的差分数组乘以i即i*d[i]的树状数组
int lowbit(int x)
{
    return x & -x;
}
void add(LL c[], int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        c[i] += v;
    }
}
LL query(LL c[], int x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        res += c[i];
    }
    return res;
}
//对应最后一步推导的公式
LL get_sum(int x)
{
    return query(tr, x) * (x + 1) - query(tri, x); //相当于补形之后进行减去
}
int main()
{
    scanf("%d%d", &n, &m);
    //输入数组a[i]
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    //先构造两个数组 d[i] 和 i*d[i]
    for (int i = 1; i <= n; ++i)
    {
        tr[i] = a[i] - a[i - 1], tri[i] = tr[i] * i;
    }
    //原地 O(n) 建树状数组
    for (int x = 1; x <= n; ++x)
    {
        for (int i = x - 1; i >= x - lowbit(x) + 1; i -= lowbit(i))
        {
            tr[x] += tr[i], tri[x] += tri[i];
        }
    }
    //读入查询
    while (m--)
    {
        int k = 0;
        int l, r, c;
        scanf("%d", &k);
        if (k == 2)
        {
            scanf("%d%d", &l, &r);
            printf("%lld\n", get_sum(r) - get_sum(l - 1));
        }
        else
        {
            scanf("%d%d%d", &l, &r, &c);
            add(tr, l, c), add(tr, r + 1, -c);
            add(tri, l, l * c), add(tri, r + 1, (r + 1) * -c);
        }
    }
    return 0;
}