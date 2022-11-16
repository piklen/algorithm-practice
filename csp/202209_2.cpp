#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int f[300050];
int a[40];
int main()
{
    int n, x, maxx = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxx += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = maxx; j >= a[i]; j--)
        {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }
    for (int i = x; i <= maxx; i++)
    {
        if (f[i] >= x)
        {
            cout << f[i] << endl;
            break;
        }
    }
    return 0;
}
//这个题可以暴力搜索但是只能拿70%的分，把问题进行抽象，看成是01背包问题，求到所有可能的解