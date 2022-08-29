#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        if (k % 4 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            if (k % 4 == 1)
            { //如果等于1，直接正着往后罗
                for (int j = 1; j <= n; j++)
                {
                    cout << j << " ";
                    if (j % 2 == 0)
                    {
                        cout << endl;
                    }
                }
            }
            else if (k % 4 == 2)
            { //等于2
                for (int j = 2; j <= n; j += 2)
                {
                    if (j % 4 != 0)
                    {
                        cout << j << " " << j - 1 << endl; //如果不等于0，倒着
                    }
                    else
                    {
                        cout << j - 1 << " " << j << endl; //否则，正着！
                    }
                }
            }
            else
            { //等于3，也正着往后罗就行
                for (int j = 1; j <= n; j++)
                {
                    cout << j << " ";
                    if (j % 2 == 0)
                    {
                        cout << endl;
                    }
                }
            }
        }
    }
    return 0;
}
//规律题，但是我没找到规律，如果以后有相关数字变换的问题，首先应该去罗列，看看有没有相关规律