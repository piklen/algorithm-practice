#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    long long ansmax = 0, ansmin = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i + 1])
        {
            ansmax += a[i];
            ansmin += a[i];
        }
        else
        {
            ansmax += a[i];
        }
    }
    cout << ansmax << endl
         << ansmin << endl;
    return 0;
}