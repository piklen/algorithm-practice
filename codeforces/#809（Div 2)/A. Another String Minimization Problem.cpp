#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1(m, 'B');
        int x;
        while (n--)
        {
            cin >> x;
            if (s1[x - 1] == 'B' && s1[m - x] == 'B') //如果两个都还没有被赋值为A那么进行数值比较，位置靠前的那个进行赋值
            {
                if (x < (m + 1 - x))
                {
                    s1[x - 1] = 'A';
                }
                else
                {
                    s1[m - x] = 'A';
                }
            }
            else //如果存在已经有赋值了，那就对没有进行赋值的那个进行赋值
            {
                if (s1[x - 1] == 'A')
                {
                    s1[m - x] = 'A';
                }
                else
                {
                    s1[x - 1] = 'A';
                }
            }
        }
        cout << s1 << endl;
    }
    return 0;
}
//就是找在相对情况下的最小字符串