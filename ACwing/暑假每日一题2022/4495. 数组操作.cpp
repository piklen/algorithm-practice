#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k;
int a[100010];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1; // unique函数的使用
    for (int i = 1; i <= k; i++)
    {
        if (i <= n)
        {
            cout << a[i] - a[i - 1] << endl; //由题意可以找到规律就是能够输出的都是a[i]-a[i-1]
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}
/*
1.学习unique函数特性，他一般是使得数组内排除相同元素，不是真正意义上的删除n = unique(a + 1, a + n + 1) - a - 1;这个写法可以求出最后数组的大小n
2.关于最终结果变成a[i]-a[i-1]这个是找规律得到，其实也就是当处理到第i个数时前面的数值都为0了就没有影响了
*/