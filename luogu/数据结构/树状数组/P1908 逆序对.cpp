#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10;
int tree[N], ranks[N], n;
long long ans;
int lowbit(int x)
{
    return x & -x;
}
struct point
{
    int num, val;
} a[N];
bool cmp(point q, point w)
{
    if (q.val == w.val)
    {
        return q.num < w.num;
    }
    return q.val < w.val;
}
void fic(int k, int x)
{
    for (int i = k; i <= n; i += lowbit(i))
    {
        tree[i] += x;
    }
}
int sum(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        ans += tree[i];
    }
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].val);
        a[i].num = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++) //离散化？
    {
        ranks[a[i].num] = i; //不知道为什么能在rank里面进行复位
    }
    for (int i = 1; i <= n; i++)
    {
        fic(ranks[i], 1);
        ans += i - sum(ranks[i]);//sum(ranks[s])算的是第i个数前有几个数小于等于它如果返回的是1说明它前面没有数比他小，那么前面所有数都比它大，构成逆序对
    }
    printf("%lld\n", ans);
    return 0;
}