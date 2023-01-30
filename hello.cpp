#include <iostream>
#include <cstring>
#include <algorithm>
const int N = 1e5 + 100;
long long a[N];
long long b[N];
long long sum[N];
bool cmp(int a, int b)
{
    return a > b;
}
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    int m;
    cin >> m;
    long long cnt = 0;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cnt = cnt + (sum[r] - sum[l - 1]);
        b[l]++;
        b[r + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + b[i];
    }
    sort(b + 1, b + n + 1, cmp);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << "b[i]:" << b[i] << endl;
        if (b[i] == 0)
        {
            break;
        }
        ans = b[i] * a[i] + ans;
    }
    cout << ans - cnt << endl;
    return 0;
}