#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<double, int>> a;
    for (int i = 0; i < n; i++)
    {
        int c, d;
        cin >> c >> d;
        double sum;
        sum = (x - c) * (x - c) + (y - d) * (y - d);
        sum = sqrt(sum);
        a.push_back({sum, i});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i <= 2; i++)
    {
        cout << a[i].second + 1 << endl;
    }
    return 0;
}