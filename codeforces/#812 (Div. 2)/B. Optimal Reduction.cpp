#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int maxn = -999;
        int pos = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > maxn)
            {
                pos = i;
                maxn = a[i];
            }
        }
        bool ok = true;
        for (int i = 0; i < pos; i++)
        {
            if (a[i] > a[i + 1])
            {
                ok = false;
                break;
            }
        }
        for (int i = pos; i < n; i++)
        {
            if (a[i] < a[pos])
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}