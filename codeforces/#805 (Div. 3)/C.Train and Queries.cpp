#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        while (k--)
        {
            int c, d;
            cin >> c >> d;
            int flag1 = false;
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == c)
                {
                    for (int j = i; j <= n; j++)
                    {
                        if (a[j] == d)
                        {
                            flag1 = true;
                            break;
                        }
                    }
                }
                if (flag1)
                {
                    break;
                }
            }
            if (flag1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
//这个题要用unordered_map去做，但是我不会这个函数