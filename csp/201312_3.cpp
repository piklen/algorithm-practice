#include <iostream>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
    int n;
    cin >> n;
    int maxh = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxh = max(a[i], maxh);
    }
    int ans = 0;
    for (int i = 1; i <= maxh; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] >= i)
            {
                int temp = j;
                while (a[temp] >= i)
                {
                    temp++;
                }
                ans = max(ans, (temp - j) * i);
                j = temp - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}