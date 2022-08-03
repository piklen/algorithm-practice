#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int const N = 1e5 + 10;
int n, q;
int a[N];
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (q--)
    {
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (a[mid] >= x) //找到最左端的那个值
            {
                r = mid; //因为是右端点等于mid所以初始时mid不需要进行加一
            }
            else
            {
                l = mid + 1;
            }
        }
        if (a[l] == x)
        {
            cout << l << " ";
            r = n - 1;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (a[mid] <= x) //找到右端点
                {
                    l = mid; //因为左端点等于右端点所以mid=（l+r+1）/2
                }
                else
                {
                    r = mid - 1;
                }
            }
            cout << r << endl;
        }
        else
        {
            cout << "-1 -1" << endl;
        }
    }
    return 0;
}
//注意二分的模板，二分就是
/*while (l<r)
{
    int mid=(l+r)/2;
    //如果用r=mid则不需要(l+r+1),否则就需要
}
*/
