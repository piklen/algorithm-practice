// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int N = 3010;
// int a[N];
// int main()
// {
//     int minn = 1e9 + 10, midd = -1, maxx = -1;
//     int flag1 = 0, flag2 = 0, flag3 = 0;
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         if (a[i] <= minn)
//         {
//             minn = a[i];
//             flag1 = i;
//         }
//         if (a[i] >= maxx)
//         {
//             maxx = a[i];
//             flag3 = i;
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (a[i] > minn && a[i] < maxx)
//         {
//             flag2 = i;
//             break;
//         }
//     }
//     if (flag1 && flag2 && flag3)
//     {
//         cout << flag1 << " " << flag2 << " " << flag3 << endl;
//     }
//     else
//     {
//         cout << "-1 -1 -1" << endl;
//     }
//     return 0;
// }
//基本思路是找到最大最小值记录下坐标，然后找是否存在中间值，如果存在中间值，那么进行输出答案，否则输出“-1 -1 -1”
//第二种思路：
/*#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    vector<pair<int, int>> v;//键值对类型的vector
    set<int> s;
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (s.count(x))//如果已经存在x那么就不进行加入
        {
            continue;
        }
        else
        {
            v.push_back({x, i});//不然就进行键值对的加入
            s.insert(x);
        }
    }
    sort(v.begin(), v.end());//此时的vector内是无序的，所以要进行排序，它是以v.first进行排序的
    if (s.size() < 3)
    {
        cout << "-1 -1 -1" << endl;
    }
    else
    {
        cout << v[0].second << " " << v[1].second << " " << v[2].second << endl;
    }
    return 0;
}
*/
//第二种思路是先利用set的去重且排序性进行处理，如果最后不同的数值大于三的话那么进行输出，注意此时的vector内是无序的，所以要先进行排序