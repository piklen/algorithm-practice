#include <iostream>
using namespace std;
int const M = 1e8 + 10;
short int flag[M];
short int primes[M];
int cnt = 0;
void is_primes(int N)
{
    for (int i = 2; i <= N; i++)
    {
        if (!flag[i])

        {
            primes[cnt++] = i;
        }
        for (int j = 0; j * primes[j] <= N; j++)
        {
            flag[i * primes[j]] = 1;
            if (i % primes[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    is_primes(n + 6);
    if (n <= 6)
    {
        cout << "No" << endl;
        return 0;
    }
    else if (n == 7)
    {
        cout << "Yes" << endl
             << "13" << endl;
        return 0;
    }
    if (flag[n - 6] == 0 && flag[n] == 0)
    {
        cout << "Yes" << endl
             << n - 6 << endl;
    }
    else if (flag[n] == 0 && flag[n + 6] == 0)
    {
        cout << "Yes" << endl
             << n + 6 << endl;
    }
    else
    {
        cout << "No" << endl;
        for (int i = n;; i++)
        {
            if (flag[i] == 0)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
//没有过因为数据较大，数组开不成
//用最简单的暴力可以过
// #include <iostream>
// #include <cmath>
// using namespace std;
// bool is_primes(int x)
// {
//     if (x < 2)
//     {
//         return false;
//     }
//     int m = sqrt(x);
//     for (int i = 2; i <= m; i++)
//     {
//         if (x % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     if (is_primes(n) == 1 && is_primes(n - 6) == 1)
//     {
//         cout << "Yes" << endl
//              << n - 6 << endl;
//     }
//     else if (is_primes(n) == 1 && is_primes(n + 6) == 1)
//     {
//         cout << "Yes" << endl
//              << n + 6 << endl;
//     }
//     else
//     {
//         cout << "No" << endl;
//         for (int i = n;; i++)
//         {
//             if ((is_primes(i) == 1 && is_primes(i + 6) == 1) || (is_primes(i) == 1 && is_primes(i - 6) == 1))
//             {
//                 cout << i << endl;
//                 return 0;
//             }
//         }
//     }
//     return 0;
// }
//欧拉筛
// void is_primes(int x)
// {
//     for (int i = 2; i <= x; i++)
//     {
//         if (!flag[i])
//         {
//             primes[cnt++] = i;
//         }
//         for (int j = 0; i * primes[j] <= x; j++)
//         {
//             flag[i * primes[j]] = 1;
//         if (i % primes[j] == 0)
//         {
//             break;
//         }
//         }

//     }
// }