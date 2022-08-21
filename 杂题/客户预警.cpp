#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
long long sum[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            // x *= 100;
            sum[i] = sum[i - 1] + x;
        }
        int k1, k2, p;
        cin >> k1 >> k2 >> p;
        for (int i = 1; i <= n; i++)
        {
            if (i < k2)
            {
                printf("0");
            }
            else
            {
                double cnt1 = (double)(sum[i] - sum[i - k1]) / (double)k1;
                double cnt2 = (double)(sum[i] - sum[i - k2]) / (double)k2;
                if (cnt1 < (double)cnt2 * p / 100)
                {
                    printf("1");
                }
                else
                {
                    printf("0");
                }
            }
        }
        cout << endl;
    }
    return 0;
}