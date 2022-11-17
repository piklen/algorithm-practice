#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 2e5 + 10;
int a[N];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            while (x % 2 == 0 && x) //只有是2的倍数时才可以去除2
            {
                cnt++;
                x /= 2;
            }
            int temp = i;
            while (temp % 2 == 0 && temp) //看是否能够在之后进行乘，
            {
                a[i]++;
                temp /= 2;
            }
        }
        if (cnt >= n)
        {
            cout << "0" << endl; //它们的乘积能够整除2的n次方
            continue;
        }
        else
        {
            bool flag = false;
            sort(a + 1, a + 1 + n, cmp);
            for (int i = 1; i <= n; i++)
            {
                if ((cnt += a[i]) >= n)
                {
                    cout << i << endl;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}