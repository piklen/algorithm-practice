#include <iostream>
using namespace std;
cosnt int N = 1e5 + 10;
int main()
{
    cin >> n;
    int minn = 99999;
    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < minn)
        {
            minn = a[i];
        }
        // if(a[i]>maxx)
        // {
        //     maxx = a[i];
        // }
    }
    int sum = 0;
    if (minn != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i] == minn;
        }
        sum += minn;
    }
    int tot = 0;
    int l, r;
    for (int i = 1; i <= n; i++)
    {
        tot = 0;
        maxx = 0;
        int t = i;
        while (a[t] != 0)
        {
            t++;
            tot++;
        }
        if (tot > maxx)
        {
            maxx = totl;
            l = i;
            r = i + t;
        }
    }
    return 0;
}