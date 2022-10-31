// #include <iostream>
// #include <iomanip>
// using namespace std;
// int n, k;
// bool flag[22];
// void dfs(int x)
// {
//     if (x > k)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             if (flag[i])
//             {
//                 cout << setw(3) << i;
//             }
//         }
//         cout << endl;
//         return;
//     }
//     for (int i = x; i <= n; i++)
//     {
//         flag[i] = true;
//         dfs(x + 1);
//         flag[i] = false;
//     }
//     // return;
// }
// int main()
// {
//     cin >> n >> k;
//     dfs(1);
//     return 0;
// }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
using namespace std;
int m, n;
const int N = 50;
int vis[N];
int ans[N];
void dfs(int x, int state)
{
    if (x > m)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << setw(3) << ans[i];
        }
        cout << endl;
        return;
    }
    for (int i = state; i <= n; i++)
    {
        ans[x] = i;
        dfs(x + 1, i + 1);
        ans[x] = 0;
    }
}
int main()
{
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}
