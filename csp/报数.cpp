// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     int a[4] = {0, 0, 0, 0};
//     cin >> n;
//     int cnt = 1;
//     int i = 1;
//     while (cnt <= n)
//     {
//         int temp = i;
//         int flag = 1;
//         if (temp % 7 == 0)
//         {
//             a[temp % 4]++;
//             flag = 0;
//         }
//         if (flag)
//         {
//             while (temp % 10)
//             {
//                 if ((temp % 10) == 7)
//                 {
//                     a[i % 4]++;
//                     flag = 0;
//                     break;
//                 }
//                 temp /= 10;
//             }
//             if (flag)
//             {
//                 cnt++;
//                 i++;
//             }
//             else
//             {
//                 i++;
//             }
//         }
//     }
//     for (int i = 0; i <= 3; i++)
//     {
//         cout << a[i] << endl;
//     }
//     return 0;
// }
//--------------------------------------------------------
//---------------------------------------------------------
//上面那种方式只有50分，不知道是为什么
// csp报数
#include <bits/stdc++.h>
using namespace std;
bool judge_seven(int a);

int main()
{
    int n;
    cin >> n;
    int sum[4] = {0};
    int num = 0;
    while (n)
    {
        num += 1;
        if (judge_seven(num))
        {
            sum[num % 4] += 1;
            continue; //跳出本次循环不执行n--语句
        }
        n--;
    }
    cout << sum[1] << endl
         << sum[2] << endl;
    cout << sum[3] << endl
         << sum[0] << endl;
    return 0;
}
bool judge_seven(int a) //判断条件
{
    int b = a;
    if (b % 7 == 0)
        return true;
    else
    {
        while (b != 0)
        {
            if (b % 10 == 7)
            {
                return true;
            }
            b /= 10;
        }
    }
}