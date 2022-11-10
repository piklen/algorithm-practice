#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100;
char g[N][N];
bool st1[N][N];
bool st2[N][N];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool check(int x, int y, int k)
{
    char c = g[x][y];
    if (c == '+' || c == 'S' || c == 'T')
    {
        return true;
    }
    if (c == '-' && k % 2 == 1)
    {
        return true;
    }
    if (c == '|' && k % 2 == 0)
    {
        return true;
    }
    if (c == '.' && k == 2)
    {
        return true;
    }
    return false;
}
void dfs1(int x, int y)
{
    st1[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int ax = x + dx[i];
        int ay = y + dy[i];
        if (ax < 0 || ax >= n || ay < 0 || ay >= m || g[ax][ay] == '#')
        {
            continue;
        }
        if (st1[ax][ay])
            continue;
        if (check(x, y, i))
            dfs1(ax, ay);
    }
}
void dfs2(int x, int y)
{
    st2[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int ax = x + dx[i];
        int ay = y + dy[i];
        if (ax < 0 || ax >= n || ay < 0 || ay >= m || g[ax][ay] == '#')
        {
            continue;
        }
        if (st2[ax][ay])
            continue;
        if (check(ax, ay, i ^ 2))
            dfs2(ax, ay);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    int ix, ij;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'S')
            {
                dfs1(i, j);
            }
            if (g[i][j] == 'T')
            {
                ix = i;
                ij = j;
                dfs2(i, j);
            }
        }
    }

    int res = 0;
    if (!st1[ix][ij])
    {
        cout << "I'm stuck!" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (st1[i][j] && !st2[i][j])
                {
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}