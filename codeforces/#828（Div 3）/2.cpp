#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, ans = 0, odd = 0, even = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ans += x;
            if (x % 2)
            {
                odd++; //这个数是奇数
            }
            else
            {
                even++; //这个数是偶数
            }
        }
        while (m--)
        {
            long long x, k;
            cin >> x >> k;
            if (x == 0) //偶数处理
            {
                ans += (k * even);
                if (k % 2) //处理的这个数是奇数
                {
                    odd += even;
                    even = 0;
                }
            }
            else //处理奇数
            {
                ans += (k * odd);
                if (k % 2)
                {
                    even += odd;
                    odd = 0;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}