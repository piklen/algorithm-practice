#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int a[60];
int b[60];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string c;
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> c;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (b[a[i]] == 0)
            {
                b[a[i]] = c[i];
            }
            else
            {
                if (b[a[i]] != c[i])
                {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}