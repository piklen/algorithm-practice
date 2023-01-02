#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 550;
string str;
int n;
int dp[N][N];
int main()
{
    cin >> str;
    n = str.length();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (str[i] == str[j])
            {
                if (j == i || j == i + 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j - i + 1 == len && dp[i][j] == 1)
                {
                    cout << str.substr(i, len) << endl;
                }
            }
        }
    }
    return 0;
}
