#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int a[40];
int flag[10][10];
int t, n, m;
int ans = 0;
int maxx = 0;
void dfs(int x, int n, int m, int a[])
{
    if (x >= n * m)
    {
        maxx = max(maxx, ans);
        return;
    }
    //不选这个数
    dfs(x + 1, n, m, a);                 //先不进行选择
    if (flag[x / m + 1][x % m + 1] == 0) //学会在矩阵中怎么判断位置
    {
        ans += a[x];
        for (int i = x / m; i <= x / m + 2; i++)//会有多余，但是用不到所以没有去限制它
        {
            for (int j = x % m; j <= x % m + 2; j++)
            {
                flag[i][j]++;
            }
        }
        dfs(x + 1, n, m, a);
        ans -= a[x];
        for (int i = x / m; i <= x / m + 2; i++)
        {
            for (int j = x % m; j <= x % m + 2; j++)
            {
                flag[i][j]--;
            }
        }
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(flag, 0, sizeof(flag));
        cin >> n >> m;
        for (int i = 0; i < n * m; i++)
        {
            cin >> a[i];
        }
        ans = 0;
        maxx = 0;
        dfs(0, n, m, a);
        cout << maxx << endl;
    }
    return 0;
}