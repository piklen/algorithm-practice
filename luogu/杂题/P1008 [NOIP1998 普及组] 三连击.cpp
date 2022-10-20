#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    int a[11];
    for (int i = 123; i <= 334; i++)
    {
        memset(a, 0, sizeof(a));
        a[i % 10] = a[i / 10 % 10] = a[i / 100] = 1;
        a[i * 2 % 10] = a[i * 2 / 10 % 10] = a[i * 2 / 100] = 1;
        a[i * 3 % 10] = a[i * 3 / 10 % 10] = a[i * 3 / 100] = 1;
        int ans = 0;
        for (int j = 1; j <= 9; j++)
        {
            ans += a[j];
        }
        if (ans == 9)
        {
            cout << i << " " << i * 2 << " " << i * 3 << endl;
        }
    }
    return 0;
}