#include <iostream>
using namespace std;
const int N = 510;
int a[N][N];
int n, m, k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j]; //只需要处理列，不需要处理行
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int l = 1, r = 1, sum = 0; r <= m; r++)//判断有边界的位置
            {
                sum += a[j][r] - a[i - 1][r];//形成大矩阵
                while (sum > k)
                {
                    sum -= a[j][l] - a[i - 1][l];//矩阵左端进行指针移动
                    l++;
                }
                ans += r - l + 1;//计算矩阵数量
            }
        }
    }
    cout << ans << endl;
    return 0;
}