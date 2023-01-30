#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        string s;
        cin >> n >> m >> k >> s;
        for (int i = 0; i + 1 < s.length(); i++)
        {
            if (s[i] != s[i + 1]) // 计算拐角量
            {
                k--, i++;
            }
        }
        cout << (k < 0 ? "No\n" : "Yes\n");
    }
    return 0;
}
// 题意自己不是特别清楚，为啥可以这样去填自己不理解