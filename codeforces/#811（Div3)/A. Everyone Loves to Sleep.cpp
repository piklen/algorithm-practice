#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, hour, miu;
        cin >> n >> hour >> miu;
        int a, b;
        vector<pair<int, int>> ss;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            int suma = hour * 60 + miu;
            int sumb = a * 60 + b;
            if (suma > sumb)
            {
                int c = (1440 + sumb - suma) / 60;
                int d = (1440 + sumb - suma) % 60;
                ss.push_back({c, d});
            }
            else
            {
                int c = (sumb - suma) / 60;
                int d = (sumb - suma) % 60;
                ss.push_back({c, d});
            }
        }
        sort(ss.begin(), ss.end());
        cout << ss[0].first << " " << ss[0].second << endl;
    }
    return 0;
}