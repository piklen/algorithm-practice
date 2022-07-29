#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int ans[150];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(ans, 0, sizeof(ans));
        string a;
        cin >> a;
        int cnt = 0;
        int ss = 0;
        for (int i = 0; i < a.size(); i++)
        {
            /*if (cnt == 3)
			{
				while (ans[a[i]])
				{
					i++;
				}
				ss++;
				cnt = 0;
				memset(ans, 0, sizeof(ans));
			}*/
            if (ans[a[i]])
            {
                while (ans[a[i]])
                {
                    i++;
                }
                i--;
                continue;
            }
            else
            {
                ans[a[i]]++;
                cnt++;
                while (ans[a[i]])
                {
                    i++;
                }
                i--;
            }
            /*if ((cnt==3)&&ans[a[i + 1]])
			{
				i++;
				continue;
			}*/
            if (cnt == 3)
            {
                ss++;
                cnt = 0;
                memset(ans, 0, sizeof(ans));
            }
        }
        if (cnt)
        {
            cout << ss + 1 << endl;
        }
        else
        {
            cout << ss << endl;
        }
    }
    return 0;
}
//用while去除掉重复的数，但是最后要i--因为这是while的特性，不减去的话最后会多算一次i的值