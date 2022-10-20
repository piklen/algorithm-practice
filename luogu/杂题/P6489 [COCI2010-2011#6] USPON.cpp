#include <iostream>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
    int n;
    cin >> n;
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i == 1)
        {
            a[i] = x;
        }
        if (i > 1)
        {
            if (x > a[t])
            {
                ++t;
                a[t] = x;
            }
        }
    }
    cout << a[t] - a[1] << endl;
    return 0;
}