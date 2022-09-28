#include <bits/stdc++.h>
using namespace std;
int n, k, ans = 0;
int a[30];
bool isprimes(int x)
{
    double sq;
    sq = sqrt(x);
    for (int i = 2; i <= sq; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
void dfs(int pos, int sum, int select)
{
    if (k == select)
    {
        if (isprimes(sum))
        {
            ans++;
        }
        return;
    }
    for (int i = pos; i <= n; i++)
    {
        dfs(i + 1, sum + a[i], select + 1);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}