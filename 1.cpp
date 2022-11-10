#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string a;
        int temp = k;
        while (temp > 0)
        {
            if (temp % n < 10)
            {
                a += (temp % n + '0');
                temp /= n;
            }
            else
            {
                a += ((temp % n - 10) + 'A');
                temp /= n;
            }
        }
        for (int i = a.size() - 1; i >= 0; i--)
        {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}