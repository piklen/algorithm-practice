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
        long long x;
        cin >> x;
        if (x % 2) //是奇数
        {
            long long sum = ((x + 1) / 2) * (1 + (x + 1) / 2) - ((x + 1) / 2);
            cout << (long long)sqrt(sum) << endl;
        }
        else
        {
            long long sum = ((x + 1) / 2) * (1 + (x + 1) / 2);
            cout << (long long)sqrt(sum) << endl;
        }
    }
    return 0;
}