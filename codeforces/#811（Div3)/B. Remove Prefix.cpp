#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
int ss[N];
int sum[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(ss, 0, sizeof(ss));
        memset(sum, 0, sizeof(sum));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ss[i];
        }
        int i, j;
        for (i = 0, j = 0; i < n; i++)
        {
            sum[ss[i]]++;
            while (sum[ss[i]] > 1)
            {
                sum[ss[j]]--;
                j++;
            }
        }
        cout << n - (i - j) << endl;
    }
    return 0;
}