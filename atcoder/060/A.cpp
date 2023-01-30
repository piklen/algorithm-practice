#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define int long long
#define mod 998244353
using namespace std;
const int N = 5050;
int f[N][30][30];
signed main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;      // 方便字符从第一个位置开始
    f[0][26][27] = 1; // 相当于进行了全局的初始化，把合法位置置为1，包括他本身就是最优解
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 27; j++)
        {
            for (int k = 0; k <= 27; k++)
            {
                if (!f[i - 1][j][k] || j == k) // 如果前一个位置没有值，或者两个相近的相同就跳过
                {
                    continue;
                }
                for (int l = 0; l < 26; l++)
                {
                    if (j == l || l == k) // 验证距离为1不相等
                    {
                        continue;
                    }
                    if (s[i] != '?' && s[i] != l + 'a') // 验证距离为2不相等
                    {
                        continue;
                    }
                    (f[i][k][l] += f[i - 1][j][k]) %= mod; //不然就状态转移
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            (ans += f[n][i][j]) %= mod;
        }
    }
    cout << ans << "\n";
    return 0;
}