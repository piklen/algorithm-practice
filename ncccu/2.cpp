#include <iostream>
#include <algorithm>
const int N = 2e5 + 10;
int a[N];
int b[100010];
bool cmp(int a, int b)
{
    return a > b;
}
using namespace std;
int main()
{
    int L, n, k;
    cin >> L >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        a[i - 1] = b[i] - b[i - 1];
    }
    a[n] = L - b[n];
    int temp = 0;
    int maxx = a[0];
    sort(a, a + n + 1, cmp);
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << a[i] << endl;
    // }
    int s = 0;
    for (int j = 1; j <= k; j++)
    {
        if (maxx == a[0])
        {
            int cc = maxx;
            int s = cc / a[1];
            if (s < k)
            {
                k -= s;
            }
            int ss = maxx % (s + 1);
            for (int i = 0; i <= s; i++)
            {
                if (i < ss)
                {
                    a[temp + n + 1 + i] = maxx / (s + 1) + 1;
                }
                else
                {

                    a[temp + n + 1 + i] = maxx / (s + 1);
                    // cout << "hdkjh" << endl;
                }
            }
            a[0] = 0;
            sort(a, a + n + 1 + temp + s + 1, cmp);
            // cout << "s:" << s << endl;
            // for (int i = 0; i <= n; i++)
            // {
            //     cout << a[i] << endl;
            // }
            // cout << "hjkdhk" << endl;
            k++;
            continue;
        }
        if (a[0] % 2)
        {
            a[temp + n + 1] = a[0] / 2 + 1;
            a[0] = a[0] / 2;
            temp++;
        }
        else
        {
            a[temp + n + 1] = a[0] / 2;
            a[0] = a[0] / 2;
            temp++;
        }

        sort(a, a + n + 1 + temp + s + 1, cmp);
    }
    cout << a[0] << endl;
    return 0;
}