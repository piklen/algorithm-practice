#include <iostream>
using namespace std;
const int N = 1010;
typedef long long LL;
LL a[N][N];
LL c[N];
const int mod = 1e9 + 7;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = (a[i - 1][j] + a[i - 1][j - 1]) % mod; //计算组合数的基本公式
            }
        }
    }
    LL res = 0;
    for (int i = 2; i <= n - 2; i++)
    {
        res = (res + (a[n - 1][i] * (i - 1) * (n - i - 1))) % mod; //进行组合数求和
    }
    cout << res << endl;
    return 0;
}
//这个主要考察的是运用动态规划的思想进行组合算数