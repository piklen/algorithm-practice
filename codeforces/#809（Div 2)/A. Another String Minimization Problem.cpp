#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1(m, 'B');
        int x;
        while (n--)
        {
            cin >> x;
            if (s1[x - 1] == 'B' && s1[m - x] == 'B')
            {
                if (x < (m + 1 - x))
                {
                    s1[x - 1] = 'A';
                }
                else
                {
                    s1[m - x] = 'A';
                }
            }
            else
            {
                if (s1[x - 1] == 'A')
                {
                    s1[m - x] = 'A';
                }
                else
                {
                    s1[x - 1] = 'A';
                }
            }
        }
        cout << s1 << endl;
    }
    return 0;
}