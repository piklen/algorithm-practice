#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, L, S;
    cin >> n >> L >> S;
    struct tree
    {
        int x;
        int y;
    } a[1010];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    int b[60][60];
    for (int i = S; i >= 0; i--)
    {
        for (int j = 0; j <= S; j++)
        {
            cin >> b[i][j];
        }
    }
    int c[60][60];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].x > (L - S) || a[i].y > (L - S))
        {
            continue;
        }
        memset(c, 0, sizeof(c));
        for (int k = 1; k <= n; k++)
        {
            int tempx = a[k].x - a[i].x;
            int tempy = a[k].y - a[i].y;
            if (tempx < 0 || tempx > S)
            {
                continue;
            }
            if (tempy < 0 || tempy > S)
            {
                continue;
            }
            c[tempx][tempy] = 1;
        }
        int flag = 0;
        for (int xx = S; xx >= 0; xx--)
        {
            for (int yy = 0; yy <= S; yy++)
            {
                if (c[xx][yy] != b[xx][yy])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
//稀疏矩阵用结构体数组来存储，然后对每一个有效值进行构建矩阵，然后对比目标矩阵