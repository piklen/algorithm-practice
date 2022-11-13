#include <iostream>
#include <cmath>
using namespace std;
int a[1100];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[abs(x)]++;
    }
    int ans = 0;
    for (int i = 0; i <= 1010; i++)
    {
        if (a[i] == 2)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
//找到关键点，相反数的判定，无疑就是他们的绝对值出现两次，所以可以运用这个规律进行统计
