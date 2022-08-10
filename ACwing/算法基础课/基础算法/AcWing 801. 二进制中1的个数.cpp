#include <iostream>
using namespace std;
int lowbit(int c)
{
    return c & (~c + 1);
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int res = 0;
        while (x > 0)
        {
            x -= lowbit(x); //可以把x看做是二进制的，返回的也是一串二进制，刚好减去
            res++;
        }
        cout << res << " ";
    }
    return 0;
}
//运用位运算求数字用2进制表示中1的数量，lowbit是源码与上补码的结果，补码就是原码的取反加一，然后每次减掉最后一个1用res统计结果