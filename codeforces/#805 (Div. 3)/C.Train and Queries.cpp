// #include <iostream>
// #include <cstring>
// #include <string>
// using namespace std;
// const int N = 2e5 + 10;
// int a[N];
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//         }
//         while (k--)
//         {
//             int c, d;
//             cin >> c >> d;
//             int flag1 = false;
//             for (int i = 1; i <= n; i++)
//             {
//                 if (a[i] == c)
//                 {
//                     for (int j = i; j <= n; j++)
//                     {
//                         if (a[j] == d)
//                         {
//                             flag1 = true;
//                             break;
//                         }
//                     }
//                 }
//                 if (flag1)
//                 {
//                     break;
//                 }
//             }
//             if (flag1)
//             {
//                 cout << "YES" << endl;
//             }
//             else
//             {
//                 cout << "NO" << endl;
//             }
//         }
//     }
//     return 0;
// }
// //这个题要用unordered_map去做，但是我不会这个函数
#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;
//const int N = 2e5 + 10;
//int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        map<int, int> map1, map2;
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            int hh;
            cin >> hh;
            if (map1[hh] == 0)
            {
                map1[hh] = i;
            }
            map2[hh] = i;
        }
        while (k--)
        {
            int c, d;
            cin >> c >> d;
            if (map1[c] && map2[d] && (map1[c] < map2[d]))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
//使用map进行数值的存储，也就是离散化吧，然后分别进行第一次出现与最后一次出现的标记，然后进行判断第一个数值第一次出现遭遇后一个数值第一次出现就好了