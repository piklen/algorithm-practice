#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
long long a[200210] = {0};
int main()
{
    for (long long i = 2; i <= 200100; i++)
    {
        long long now = i, ans = 0;
        while (now % 2 == 0 && now)
        {
            ans++;
            now /= 2;
        }
        a[i] = ans;
    } // quan'bu

    long long _;
    cin >> _;
    while (_--)
    {
        long long n, d, sum = 0, ans = 0, flag = 0, count = 0;
        cin >> n;

        for (long long i = 1; i <= n; i++)
        {
            long long num;
            cin >> num;
            while (num % 2 == 0 && num)
            {
                sum++;
                num /= 2;
            }
        }
        if (sum >= n)
        {
            cout << 0 << endl;
            flag = 1;
        }
        else
        {
            long long s1 = 0, f1 = 0;
            sort(a, a + n + 1);
            for (long long i = n; i >= 0; i--)
            {
                if (a[i] == 0)
                {
                    break;
                }
                f1++;
                if ((sum += a[i]) >= n)
                {
                    flag = 1;
                    cout << f1 << endl;
                    break;
                }
            }
        }

        if (!flag)
        {
            cout << -1 << endl;
        }
    }
}
