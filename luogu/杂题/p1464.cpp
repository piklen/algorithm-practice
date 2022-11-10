#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;
LL f[100][100][100];
LL dfs(LL a, LL b, LL c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20)
    {
        return dfs(20, 20, 20);
    }
    else if (f[a][b][c] != 0)
    {
        return f[a][b][c];
    }
    else if (a < b && b < c)
    {
        f[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
    }
    else
    {
        f[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
    }
    return f[a][b][c];
}
int main()
{
    LL a, b, c;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
        {
            return 0;
        }
        else
        {
            printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dfs(a, b, c)); //注意输出格式，自己在输出格式上出现很多的错误，特别是空格这类
        }
    }
    return 0;
}