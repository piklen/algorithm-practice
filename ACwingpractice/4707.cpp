// #include <iostream>
// #include <cmath>
// using namespace std;
// const int N = 1010;
// int a[N];
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     a[0] = a[n];
//     int maxx = 9999;
//     for (int i = 1; i <= n; i++)
//     {
//         maxx = min(maxx, abs(a[i - 1] - a[i]));
//     }
//     cout << maxx << endl;
//     return 0;
// }

// //简单枚举问题，可以将最后一个数赋值到第一个数，从而使得构成循环。
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, a, b, ans = 99999;
    int begin = 0;
    cin >> n >> a;
    begin = a;
    for (int i = 2; i <= n; i++)
    {
        cin >> b;
        ans = min(ans, abs(b - a));
        a = b;
    }
    ans = min(ans, abs(b - begin));
    cout << ans << endl;
    return 0;
}
//用两个变量来存值，可以节省空间