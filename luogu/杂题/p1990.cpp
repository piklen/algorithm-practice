#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int f[N] = {0, 1, 2}, g[N] = {0, 0, 1, 2};
int main()
{
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2] + g[i - 1] * 2) % 10000;
        g[i] = (f[i - 2] + g[i - 1]) % 10000;
    }
    cout << f[n] << endl;
    return 0;
}
//递推关系式，先考虑只有竖条条，从后向前看，f[n]=f[n-1]+f[n-2]然后因为有“L"型设L型的为g,最后一个只能是横竖，或者竖横
//有两种最靠前的位置是第n-1个，对于L型最后只能以L的方式结束，或者加一个“一”所以有g[n]=g[n-1]+f[n-2]