#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int cnt[1445];
int main()
{
    int a, b, r, t;
    int sum;
    cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d:%d%d", &a, &b, &r); //复杂输入使用scanf
        sum = a * 60 + b;             //进行转值，好进行+r的处理
        int begin = sum;              //标记开始值
        int ans = 0;
        if (a % 10 == b / 10 && a / 10 == b % 10) //如果其自身就是回文，那么进行加一
        {
            if (cnt[sum] == 0)
            {
                ans++;
                cnt[sum] = true;
            }
        }
        //int s = 1440 / r;
        while (true)
        {
            sum = (sum + r) % 1440; //可能出现在第二天
            if (sum == begin)       //如果过了一天了，说明所以可能都已经进行遍历完了
            {
                break;
            }
            a = sum / 60;
            b = sum % 60;
            if (a % 10 == b / 10 && a / 10 == b % 10)
            {
                //ans++;
                ////cout << a << b << endl;
                if (cnt[sum] == 0) //主要是避免重复，感觉可以不需要
                {
                    ans++;
                    cnt[sum] = true;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
//转表求回文串，首先在输入方式上可以用scanf进行输入，这样比较好处理，其次注意周期是一天