#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    int a[1100];
    fill(a, a + 1100, 1);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            a[i] += a[j];
        }
    }
    cout << a[n] << endl;
    return 0;
}