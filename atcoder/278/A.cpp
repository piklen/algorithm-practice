#include <iostream>
using namespace std;
int a[200];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (m >= n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "0 ";
        }
        cout << endl;
    }
    else
    {
        for (int i = m + 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        for (int i = 1; i <= m; i++)
        {
            cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}