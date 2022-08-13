#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n < 10)
        {
            cout << n << endl;
            continue;
        }
        string ans;
        for (int i = 9; i > 0; i--)
        {
            if (n >= i)
            {
                n -= i;
                string a;
                a = to_string(i);
                ans += a;
            }
            if (n == 0)
            {
                break;
            }
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
