#include <iostream>
using namespace std;
int a[2000];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    a[0] = n * m;
    int maxx = -9999;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            if (x)
            {
                a[x]++;
                a[0]--;
            }
            if (x > maxx)
            {
                maxx = x;
            }
        }
    }
    for (int i = 0; i <= maxx; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}