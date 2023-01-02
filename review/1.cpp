#include <iostream>
using namespace std;
int main()
{
    int a[] = {0, 2, 4, 56, 67, 6, 8, 78, 8, 85, 3};
    int sum[15][15] = {0};
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (j < i)
            {
                continue;
            }
            else
            {
                sum[i][j] = sum[i][j - 1] + a[j];
            }
        }
    }
    int l, r;
    cin >> l >> r;
    cout << sum[l][r] << endl;
    return 0;
}