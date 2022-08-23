#include <iostream>
using namespace std;
const int N = 10;
char s[N][N];
int n, lie[N], xs[N], xx[N];
void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!lie[i] && !xs[i + x] && !xx[i - x + n])//如果这一列，与斜上对角线，以及斜下对角线还没有值
        {
            s[x][i] = 'Q';
            lie[i] = xs[i + x] = xx[i - x + n] = true;
            dfs(x + 1);
            s[x][i] = '.';//状态恢复
            lie[i] = xs[i + x] = xx[i - x + n] = false;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}