#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a;
int main()
{
    int T;
    cin >> T;
    for (int s = 1; s <= T; s++)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0, t = m;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (t == a) //如果他们这个数是相等的就进行减减
            {
                t--;
                if (t == 0) // 1--后等于0，就证明是倒数的
                {
                    ans++;
                    t = m;
                }
            }
            else
            {
                if (t == a - 1) //第一种情况如果是44443，选择这个判断就是不断的继承前面的状态
                {
                    continue;
                }
                else
                {
                    if (a == m) //第二种情况4343我们要选择重回前一种状态
                    {
                        t = a - 1;
                    }
                    else
                    {
                        t = m;
                    }
                }
            }
        }
        cout << "Case"
             << " #" << s << ": " << ans << endl;
    }
    return 0;
}
//纯模拟题目，case种类比较多，需要自己去找到没有想到的case