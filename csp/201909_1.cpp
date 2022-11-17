#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0, maxx = 0;
    int id = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans += x;
        int temp = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            temp += abs(x);
        }
        if (temp > maxx)
        {
            maxx = temp;
            id = i;
        }
        ans -= temp;
    }
    cout << ans << " " << id << " " << maxx << endl;
    return 0;
}
//基本的模拟