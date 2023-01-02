#include <iostream>
#include <cstring>
using namespace std;
int T, n, m, i, l, r, sum;
string s, t;
int main()
{

    cin >> T;
    while (T--)
    {
        cin >> s >> t;
        n = s.size(), s = " " + s + s;
        m = t.size(), t = " " + t;
        if (n < m)
        {
            cout << "N\n";
            continue;
        }
        for (i = 1; i <= n; i++)
        {
            l = i, r = 1, sum = 0;
            while (l <= i + n - 1 && r <= m)
            {
                if (s[l] == t[r])
                {
                    l++, r++, sum++;
                }
                else
                {
                    l++;
                }
            }
            if (sum == m)
            {
                break;
            }
        }
        cout << (i > n ? "N\n" : "Y\n");
    }
    return 0;
}
