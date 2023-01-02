#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long a = pow((double)n, 0.3333333333333333333) - 1;
    long long b = pow((double)m, 0.3333333333333333333) + 1;
    // cout << a << " " << b << endl;

    long long sum = 0;
    for (long long i = a; i <= b; i++)
    {
        long long cnt = i * i * i;
        // cout << "cnt:" << cnt << endl;
        if ((i * i * i < n) || (i * i * i) > m)
        {
            continue;
        }
        if (cnt % k == 0)
        {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}