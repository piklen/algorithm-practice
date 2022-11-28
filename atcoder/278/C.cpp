#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    map<pair<int, int>, bool> mp;
    while (k--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            mp[{b, c}] = true;
        }
        else if (a == 2)
        {
            mp[{b, c}] = false;
        }
        else
        {
            if (mp[{b, c}] && mp[{c, b}])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}