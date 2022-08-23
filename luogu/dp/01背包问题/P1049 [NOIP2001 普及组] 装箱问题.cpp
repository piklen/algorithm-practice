//第一种
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20010;
int f[N];
int main()
{
    int m, n;
    cin >> m >> n;
    int v;
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        for (int j = m; j >= v; j--)
        {
            f[j] = min(f[j], f[j - v] - v); //因为f[N]中初始化全部都为0，所以用min找最小的，并且集装箱内是有空间的
        }
    }
    cout << f[m] + m << endl; //因为初始时f[N]内是0所以最后出来肯定是负数，所以加上容量，就是剩余的最小容量
    return 0;
}
//第二种
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 20010;
int f[N];
int main()
{
    int m, n;
    cin >> m >> n;
    int v;
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        for (int j = m; j >= v; j--)
        {
            f[j] = max(f[j], f[j - v] + v); //把v看做是权值，所以找最大的值，且放得下的最大的值
        }
    }
    cout << m - f[m] << endl; //容量减去最大的值，刚好就是剩余的值
    return 0;
}