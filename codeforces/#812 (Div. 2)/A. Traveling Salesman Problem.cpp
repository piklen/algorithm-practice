#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin >> n;
        int lmin = 0, rmax = 0, dmin = 0, umax = 0;
        for (int i; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x > 0)
            {
                rmax = max(rmax, x);
                if (y > 0)
                {
                    umax = max(umax, y);
                }
                else
                {
                    dmin = min(dmin, y);
                }
            }
            else
            {
                lmin = min(lmin, x);
                if (y > 0)
                {
                    umax = max(umax, y);
                }
                else
                {
                    dmin = min(dmin, y);
                }
            }
        }
        int ans = (abs(lmin) + abs(dmin) + umax + rmax) * 2;
        cout << ans << endl;
    }
    return 0;
}