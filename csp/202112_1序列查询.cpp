#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[300];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    long long ans = 0;
    if (k >= a[n])
    {
        for (int i = k; i > 0; i = a[n + 1])
        {
            ans += (i - a[n]) * n;
            n--;
        }
    }
    else
    {
        int flag = 0;
        for (int i = n; i >= 0; i--)
        {
            if (a[i] <= k)
            {
                flag = i;
                break;
            }
        }
        for (int i = flag; i > 0; i = a[n + 1])
        {
            ans += (i - a[n]) * n;
            n--;
        }
    }
    cout << ans << endl;
    return 0;
}