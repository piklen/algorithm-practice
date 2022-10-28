#include <iostream>
using namespace std;
char a[11][11][11];
int b[11][11][11];
int kk, n, m;
int ans = 0;
void dfs(int k, int x, int y)
{
    if (k <= 0 || k > kk || x <= 0 || x > n || y <= 0 || y > m || a[k][x][y] == '#')
    {
        return;
    }
    ans++;
    a[k][x][y] = '#';
    dfs(k + 1, x, y);
    dfs(k, x + 1, y);
    dfs(k, x, y + 1);
    dfs(k - 1, x, y);
    dfs(k, x - 1, y);
    dfs(k, x, y - 1);
}
int main()
{
    int x, y;
    cin >> kk >> n >> m;
    for (int i = 1; i <= kk; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
            {
                cin >> a[i][j][k];
            }
        }
    }
    cin >> x >> y;
    dfs(1, x, y);
    cout << ans << endl;
    return 0;
}
// dfs问题，自己没有想明白的点是怎么高效的进行状态表示，他人的做法是直接改变方块状态即可，自己可以来学习这种思想