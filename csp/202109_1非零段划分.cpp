#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int cnt[10010];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    n = unique(a + 1, a + n + 1) - (a + 1); //相邻重复元素在这个问题中对岛礁数量的统计没有影响
    a[0] = 0;
    a[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i - 1];
        int y = a[i];
        int z = a[i + 1];
        if (y > x && y > z) //如果呈现出大A形状就相当于多了一个岛
        {
            cnt[y]++;
        }
        if (y < x && y < z) //如果是倒A就相当于两座岛连起来了成了一座岛，所以减少了一座岛
        {
            cnt[y]--;
        }
        //延续的情况没有影响
    }
    int sum = 0;
    int ans = 0;
    for (int i = 10000; i >= 1; i--) //海平面从最高开始降低，统计前缀和
    {
        sum += cnt[i];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
//分析后发现是模拟类似的，可以把它看做是一个海平面下降或者上升然后岛礁出现数量的问题
//这个问题中我学到的是逆向思路比正向要好，而且要把问题同实践联系起来会更好的理解