#include <iostream>
using namespace std;
int a[2600][1500];
struct cc
{
    int x1, x2, y1, y2;
} aa[20];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int kk = 1; kk <= n; kk++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        aa[kk].x1 = x1, aa[kk].x2 = x2, aa[kk].y1 = y1, aa[kk].y2 = y2;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                a[i][j] = kk;
            }
        }
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (a[x][y])
        {
            cout << a[x][y] << endl;
            for (int i = aa[a[x][y]].x1; i <= aa[a[x][y]].x2; i++)
            {
                for (int j = aa[a[x][y]].y1; j <= aa[a[x][y]].y2; j++)
                {
                    a[i][j] = a[x][y];
                }
            }
        }
        else
        {
            cout << "IGNORED" << endl;
        }
    }
    return 0;
}
//暴力直接进行解决