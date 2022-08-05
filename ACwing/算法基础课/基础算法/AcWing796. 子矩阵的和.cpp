#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
int sum[N][N];
int a[N][N];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j]; //二维前缀和的构建
        }
    }
    int x1, x2, y1, y2;
    while (k--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << endl; //二维矩阵内和
    }
    return 0;
}
//二维前缀和，明白数列是x轴，横排是y轴