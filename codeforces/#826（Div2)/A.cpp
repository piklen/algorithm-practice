#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int sum1[30];
int sum2[30];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        for (int i = 0; i < a.size(); i++)
        {
            sum1[a[i] - 'a']++;
            sum2[a[i] - 'a']++;
        }
        string s;
        for (int i = 0; i < 30; i++)
        {
            while (sum1[i] != 0)
            {
                s += (i + 'a');
                sum1[i]--;
            }
        }
        for (int i = 26; i >= 0; i--)
        {
            while (sum2[i] != 0)
            {
                s += (i + 'a');
                sum2[i]--;
            }
        }
        cout << s << endl;
    }
    return 0;
}