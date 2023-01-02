#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int a[N], b[N];
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= a[i]; j--)
        {
            f[j] = max(f[j], f[j - a[i]] + b[i]);
        }
    }
    cout << f[n] << endl;

    return 0;
}
