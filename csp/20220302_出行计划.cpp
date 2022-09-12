#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 3e5 + 10;
int a[N], sum[N];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        if ((x - y) < 1)
        {
            a[1]++;
            a[x + 1]--;
        }
        else
        {
            a[x + 1 - y]++;
            a[x + 1]--;
        }
    }
    for (int i = 1; i < N; i++)
    {
        sum[i] = sum[i - 1] + a[i];
    }
    while (m--)
    {
        int x;
        cin >> x;
        cout << sum[x + k] << endl;
    }
    return 0;
}
//主要知识点是前缀和与差分，特点是对一个区间进行操作，第一次提交只有90分原因是数组开小了，所以在以后做题要习惯性的检查数据范围