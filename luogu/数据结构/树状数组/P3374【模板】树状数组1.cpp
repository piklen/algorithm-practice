#include <iostream>
#include <cstdio>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n, m;
int lowbit(int x)
{
    return x & -x; //返回二进制表示中最后一个1所在位置表示的数
}
int sum(int x)
{
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) //这个地方i要>0不然会出现死循环
    {
        ans += a[i];
    }
    return ans;
}
void fic(int k, int x)
{
    for (int i = k; i <= n; i += lowbit(i)) //修改所以与这个数相关的数
    {
        a[i] += x;
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        fic(i, x);
        // scanf("%d", &a[i]);//这一步不能直接写成输入就完事了，它还有一个建表的作用，所以要进行建表操作
    }
    while (m--)
    {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k == 1)
        {
            fic(x, y); //数据修改
        }
        else
        {
            printf("%d\n", sum(y) - sum(x - 1));
        }
    }
    return 0;
}
//树状数组能快速实现对一个数的修改，并且求前缀和的操作，时间复杂度为O(nlogn);