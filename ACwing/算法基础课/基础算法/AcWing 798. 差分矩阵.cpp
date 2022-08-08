#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
int a[N][N], b[N][N];
void insert(int x1, int y1, int x2, int y2, int c) //差分是向后看的，右下方看
{
    b[x1][y1] += c; //对b[x1][y1]后的所有数都进行加C,所有要减回来
    b[x2 + 1][y1] -= c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y2 + 1] += c;
}
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            insert(i, j, i, j, a[i][j]); //构建差分，差分构建有点奇葩，是左上到右下为+,左下到右上为-
            //相当于这样去写
            //b[i][j] = a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
        }
    }
    while (t--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[i][j] = b[i - 1][j] + b[i][j - 1] + b[i][j] - b[i - 1][j - 1]; //差分的前缀和就是输入的那个数，所以要进行前缀和运算，来得出最后的结果
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//差分的前缀和是原输入数组