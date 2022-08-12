#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main()
{
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; Case++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i + 2;                                          //因为任意两个数都构成等差数列，只需要判断低三个数，就好了
            while (j < n && a[j] - a[j - 1] == a[j - 1] - a[j - 2]) //判断第三个数是否符合题意
            {
                j++; //符合等差，就进行加一
            }
            res = max(res, j - i); // j-i最小值为2
            i = j - 2;             //假设没有进循环，就是把i值复原，进了循环几次i值就会增大几次，因为退出循环的条件是
            //不满足a[j] - a[j - 1] == a[j - 1] - a[j - 2]此时只有[i,j-1]是满足的，所以让i为j-2,下一次进来为i++==j-1;
        }
        printf("Case #%d: %d\n", Case, res);
    }
    return 0;
}
//题意：求区间内最长等差序列，可以用差分或者双指针来做