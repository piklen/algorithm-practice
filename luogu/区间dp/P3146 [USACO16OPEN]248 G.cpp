#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 500;
int f[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i][i];
    }
    int maxx = -0x7fffffff;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                if (f[i][k] == f[k + 1][j]) //根据2048规则，如果前面i到k的值等于k+1到j的值，就可以选择合并
                {
                    f[i][j] = max(f[i][j], f[i][k] + 1); //找到i到j，或者选择i到k+1之间数值较大的
                }
                maxx = max(maxx, f[i][j]); //选择出每一轮状态的最大值
            }
        }
    }
    cout << maxx << endl;
    return 0;
}
//其实自己感觉这个题自己还是不能特别的理解f[i][j] = max(f[i][j], f[i][k] + 1);这句话的状态表示意思