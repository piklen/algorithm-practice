#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e8 - 3;
int c[N], tree[N];
struct p
{
    int val, id;
} a[N], b[N];
int n;
long long ans;
int lowbit(int x)
{
    return x & -x;
}
bool cmp(p f, p d)
{
    if (f.val == d.val)
    {
        return f.id < d.id;
    }
    return f.val < d.val;
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i].val = x;
        a[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        b[i].val = x;
        b[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);//val值进行排序，从小到大
    for (int i = 1; i <= n; i++)
    {
        c[a[i].id] = b[i].id;
    }
    for (int i = 1; i <= n; i++)
    {
        fic(c[i], 1);
        ans += i - sum(c[i]);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
//贪心的依据是最大的对最大的，最后差得到的是最小的