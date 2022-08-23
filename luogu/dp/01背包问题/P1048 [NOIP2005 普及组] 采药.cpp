#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1110;
int v[N];
int t[N];
int f[N];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= t[i]; j--) //当剩余时长大于t[i]时有选与不选两种选择
        {
            f[j] = max(f[j], f[j - t[i]] + v[i]); // f[j]的状态就是为f[j-1]的状态，f[j-t[i]]+v[i]表示如果选择所能产生的价值
        }
    }
    cout << f[m] << endl;
    return 0;
}