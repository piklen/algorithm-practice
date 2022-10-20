#include <iostream>
using namespace std;
int n, k;
const int mod = 100003;
int a[1000000];
int main()
{
    cin >> n >> k;
    a[0] = a[1] = 1; //初始条件
    for (int i = 2; i <= n; ++i)
    {
        if (i <= k)
        {
            a[i] = a[i - 1] * 2 % mod; //取模
        }
        else
        {
            a[i] = a[i - 1] * 2 - a[i - k - 1], a[i] %= mod; //取模
        }
    }
    cout << (a[n] +mod) % mod << endl; //防止有负数
    return 0;
}