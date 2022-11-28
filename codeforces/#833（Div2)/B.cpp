#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int a[100];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int maxx = 0;
            memset(a, 0, sizeof(a));
            int df = 0;
            for (int j = i; j < min(n, i + 100); j++) //当字符串长度超过10*10后不可能出现不同种类数量大于等于最大长度的情况
            {
                if (a[s[j] - '0'] == 0)
                {
                    df++;
                }
                a[s[j] - '0']++;
                maxx = max(maxx, a[s[j] - '0']);
                if (df >= maxx)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}