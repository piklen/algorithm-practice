#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{

    int m, n;
    while (true)
    {
        int ans = 0;
        cin >> m >> n;
        if (m == 0 && n == 0)
        {
            break;
        }
        for (int i = m; i <= n; i++)
        {
            if (i == ((i % 10) * (i % 10) * (i % 10) + (i % 100 / 10) * (i % 100 / 10) * (i % 100 / 10) + (i / 100) * (i / 100) * (i / 100)))
            {
                cout << i << " ";
                ans++;
            }
        }
        if (ans == 0)
        {
            cout << "no";
        }
        cout << endl;
    }
    return 0;
}
//水仙花数，简单的一个数的分解就好了，外加一个while循环