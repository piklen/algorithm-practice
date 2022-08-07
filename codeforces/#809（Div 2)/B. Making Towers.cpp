#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int N = 2e5 + 10;
int flag[N], cnt[N], a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        memset(flag, 0, sizeof(flag));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= x; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= x; i++)
        {
            if (flag[a[i]] == 0)
            {
                cnt[a[i]]++;
                flag[a[i]] = i;
            }
            else if ((i - flag[a[i]] - 1) % 2 == 0)
            {
                cnt[a[i]]++;
                flag[a[i]] = i;
            }
        }
        for (int i = 1; i <= x; i++)
        {
            cout << cnt[i] << " ";
        }
        cout << endl;
    }
    return 0;
}