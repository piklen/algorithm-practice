#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int N = 2e5 + 10;
int flag[N], cnt[N], a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        memset(flag, 0, sizeof(flag));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= x; i++)
        {
            cin >> a[i]; //存储高度
        }
        for (int i = 1; i <= x; i++)
        {
            if (flag[a[i]] == 0) //如果是开始，也就是这个颜色的第一快
            {
                cnt[a[i]]++;    //这个颜色能够搭建的高度加一
                flag[a[i]] = i; //这个颜色最后在的位置标记一下
            }
            else if ((i - flag[a[i]] - 1) % 2 == 0) //如果是同种颜色并且相差偶数快，就能够搭在一起
            {
                cnt[a[i]]++;
                flag[a[i]] = i;
            }
        }
        for (int i = 1; i <= x; i++)
        {
            cout << cnt[i] << " "; //输出每一个方块所属颜色的最高搭建高度
        }
        cout << endl;
    }
    return 0;
}
//叠方块，方块只能左右上，不能下，还要考虑颜色，最终使得能够使得方块达到最高的位置，最优解是按照左右上左，或者右上左的方式
//当然前提是能够同颜色，也就是同颜色之间要能够搭在一起，数值至少隔偶数个