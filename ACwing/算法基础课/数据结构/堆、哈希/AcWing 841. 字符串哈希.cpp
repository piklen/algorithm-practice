#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef unsigned long long ll;
const int N = 1e5 + 10, P = 131; // 131 13331
ll h[N], p[N];
ll query(int l, int r) //求l到r之间的这段哈希值
{
    return h[r] - h[l - 1] * p[r - l + 1]; //后半段减去前半段，但是里面还有一个幂次方的倍数
}
int main()
{
    int n, m;
    cin >> n >> m;
    string x;
    cin >> x;
    p[0] = 1;
    h[0] = 0;
    for (int i = 0; i < n; i++)
    {
        p[i + 1] = p[i] * P;        //应该还要mod2e64,但这是一个很大的数，我感觉可能会越界，p进制表示
        h[i + 1] = h[i] * P + x[i]; //前缀和求整个字符串的哈希值
    }
    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (query(l1, r1) == query(l2, r2)) //如果两段的哈希值相等，那么这两个一定相等
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
//哈希实现判断一定区间内是否相等