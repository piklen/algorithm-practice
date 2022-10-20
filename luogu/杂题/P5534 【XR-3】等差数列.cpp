#include <iostream>
using namespace std;
int main()
{
    long long a, b, n; //会爆int
    cin >> a >> b >> n;
    long long ans = 0;
    ans = n * a + n * (n - 1) * (b - a) / 2;
    cout << ans << endl;
}