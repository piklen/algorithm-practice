#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
struct Range
{
    int l, r;
} range[N];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    sort(range, range + n, [&](Range a, Range b)
         { return a.r < b.r; });
    int ans = 0;
    int ed = -2e9;
    for (int i = 0; i < n; i++)
    {
        if (range[i].l > ed)
        {
            ans++;
            ed = range[i].r;
        }
    }
    cout << ans << endl;
    return 0;
}