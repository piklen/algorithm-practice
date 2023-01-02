#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    long long n, m;
    cin >> n >> m;
    if (m < (n / 2))
    {
        cout << "-1" << endl;
    }
    else if (m == (n / 2))
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        if (n % 2) // n为奇数
        {
            cout << (m - ((n - 3) / 2)) << " " << 2 * (m - ((n - 3) / 2)) << " ";
            int temp = 1;
            cout << "temp" << endl;
            for (int i = 3; i <= n; i++)
            {
                cout << "i:" << i << "temp:" << temp << endl;
                if ((temp == (m - ((n - 3) / 2))) || (temp == (2 * (m - ((n - 3) / 2)))))
                {
                    temp += 2;
                    while ((temp == (m - ((n - 3) / 2))) || (temp == (2 * (m - ((n - 3) / 2)))))
                    {
                        temp += 2;
                    }
                    cout << temp << " ";
                }
                else
                {
                    cout << temp << " ";
                    temp++;
                }
            }
            cout << endl;
        }
        else
        {
            cout << (m - ((n - 2) / 2)) << " " << 2 * (m - ((n - 2) / 2)) << " ";
            int temp = 1;
            for (int i = 2; i <= n; i++)
            {
                if ((temp == (m - ((n - 2) / 2))) || (temp == (2 * (m - ((n - 2) / 2)))))
                {
                    temp += 2;
                    while ((temp == (m - ((n - 2) / 2))) || (temp == (2 * (m - ((n - 2) / 2)))))
                    {
                        temp += 2;
                    }
                    cout << temp << " ";
                }
                else
                {
                    cout << temp << " ";
                    temp++;
                }
            }
            cout << endl;
        }
    }
    return 0;
}