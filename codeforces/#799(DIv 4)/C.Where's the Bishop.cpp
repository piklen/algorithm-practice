#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
char a[9][9];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 2; i <= 7; i++)
        {
            for (int j = 2; j <= 7; j++)
            {
                if (a[i][j] == '#' && a[i - 1][j - 1] == '#' && a[i - 1][j + 1] == '#' && a[i + 1][j - 1] == '#' && a[i + 1][j + 1] == '#')
                {
                    cout << i << " " << j << endl;
                    break;
                }
            }
        }
    }
    return 0;
}