#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int cnt[1445];
int main()
{
    int a, b, r, t;
    int sum;
    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d:%d%d", &a, &b, &r);
        sum = a * 60 + b;
        int begin = sum;
        int ans = 0;
        if (a % 10 == b / 10 && a / 10 == b % 10)
        {
            if (cnt[sum] == 0)
            {
                ans++;
                cnt[sum] = true;
            }
        }
        //int s = 1440 / r;
        while (true)
        {
            sum = (sum + r) % 1440;
            if (sum == begin)
            {
                break;
            }
            a = sum / 60;
            b = sum % 60;
            if (a % 10 == b / 10 && a / 10 == b % 10)
            {
                //ans++;
                ////cout << a << b << endl;
                if (cnt[sum] == 0)
                {
                    ans++;
                    cnt[sum] = true;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}