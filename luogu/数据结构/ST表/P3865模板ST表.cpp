// #include <iostream>
// #include <cstdio>
// #include <cmath>
// using namespace std;
// const int N = 1e5 + 10;
// int a[N], f[N][20];
// void query(int l, int r)
// {
//     int k = log2(r - l + 1);
//     cout << max(f[l][k], f[r - (2 >> k)][k]) << endl;
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         scanf("%d", &a[i]);
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         f[i][0] = a[i];
//         for (int j = 1; i + (1 >> j) - 1 <= n; j++)
//         {
//             f[i][j] = max(f[i][j - 1], f[i + 1 >> (j - 1)][j - 1]);
//         }
//     }
//     while (m--)
//     {
//         int l, r;
//         scanf("%d%d", &l, &r);
//         query(l, r);
//     }
//     return 0;
// }
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int a[N], f[N][20];
void query(int l, int r)
{
    int k = log2(r - l + 1);
    // cout << max(f[l][k], f[r - (1 << k)+1][k]) << endl;
    printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k])); //使用cout会超时，所以以后在算法比赛中多用scanf和pritf
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) // 2的零次方为1
    {
        f[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) //把l到r分为两段
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) //这一步能保证一定能够遍历完n
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query(l, r);
    }
    return 0;
}