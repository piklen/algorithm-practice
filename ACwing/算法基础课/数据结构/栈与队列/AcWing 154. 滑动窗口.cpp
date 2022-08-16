#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int N = 1e6 + 10;
int hh, tt, n, k, q[N], a[N];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    hh = 0;
    tt = -1; //队头队尾初始化
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && k < i - q[hh] + 1) //到达i时如果这个区间范围超过了k个，那么队头进行指针移动
        {
            hh++;
        }
        while (hh <= tt && a[q[tt]] >= a[i]) //如果队尾元素大于当前元素，那么队尾元素出列，因为要找区间中最小值
        {
            tt--;
        }
        q[++tt] = i; //当前元素入队
        if (i + 1 >= k)
        {
            cout << a[q[hh]] << " ";//队头一定是最小的
        }
    }
    cout << endl;
    // memset(q, 0, sizeof 0);
    hh = 0;
    tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && k < i - q[hh] + 1)
        {
            hh++;
        }
        while (hh <= tt && a[q[tt]] <= a[i])
        {
            tt--;
        }
        q[++tt] = i;
        if (i + 1 >= k)
        {
            cout << a[q[hh]] << " ";
        }
    }
    return 0;
}
//队列实现区间的移动，用队列这个性质来控制单调性，最终找到区间内所求元素