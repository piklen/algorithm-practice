#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int sum[N];
int main()
{
    int n, k;
    cin >> n >> k;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum[i] = sum[i - 1] + x; //简单前缀和公式
    }
    int l, r;
    while (k--)
    {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl; //利用前缀和求解
    }
    return 0;
}