#include <iostream>
using namespace std;
long long fuc(int n)
{
    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int m, n;
    cin >> m >> n;

    long long P = fuc(m) / (fuc(n) * fuc(m - n));
    cout << P << endl;

    return 0;
}
