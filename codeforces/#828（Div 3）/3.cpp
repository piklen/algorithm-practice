#include <iostream>
#include <algorithm>
using namespace std;
const int N = 4e5 + 10;
char a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        char c;
        cin >> n;
        cin >> c;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i + n] = a[i];
        }
        int ans = 0;
        for (int i = 1; i <= 2 * n; i++)
        {
            if (a[i] == c)
            {
                int k = i;
                while (a[k] != 'g' && k <= 2 * n)
                {
                    k++;
                }
                ans = max(ans, (k - i));
                i = k;
            }
        }
        cout << ans << endl;
    }
    return 0;
}