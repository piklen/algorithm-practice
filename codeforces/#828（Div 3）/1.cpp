#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int a[60];
int b[60];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[x]++;
        }
        for (int i = 0; i < n; i++)
        {
            char x;
            cin >> x;
            b[x - 'a']++;
        }
        sort(a, a + 55);
        sort(b, b + 30);
        for (int i = 0; i < n; i++)
        {
        }
    }
    return 0;
}