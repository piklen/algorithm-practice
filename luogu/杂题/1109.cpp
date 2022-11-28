#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[60];
int main()
{
    int n;
    cin >> n;
    long long sum = 0, more = 0, less = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    long long L, R;
    cin >> L >> R;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < L)
        {
            less += abs(L - a[i]);
        }
        if (a[i] > R)
        {
            more += abs(R - a[i]);
        }
    }
    if (L * n > sum || R * n < sum)
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << max(less, more) << endl;
    return 0;
}
//贪心的基本思想，先求出看是否可以符合移动的条件，即数量满足下限，且不高于上限，然后因为移动一个是一一对应的所以只需要取max