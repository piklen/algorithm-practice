#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        for (int i = 0; i <= 10; i++)
        {
            long long cnt = pow(10, i);
            if (cnt > n)
            {
                cnt = pow(10, i - 1);
                cout << n - cnt << endl;
                break;
            }
        }
    }
    return 0;
}
//1.先找到大于输入数的那个次方，然后用输入数减去那个小于的次方就好了