#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10010;
int f[N];
int a[110];
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    f[0] = 1;                   //把f[0]设置为1，表示当余额全部用完时方案次数加一
    for (int i = 0; i < m; i++) //最多m种点菜方案
    {
        for (int j = n; j >= a[i]; j--) //余额总量为j,从最多开始减，当菜品价格小于剩下的钱时，可以进行选择是选这种菜与不选这种菜
        //
        {
            f[j] = f[j] + f[j - a[i]]; //到达某一个价格的话就是全部方案数，选与不选之和，其实不选里面有两种可能，但是受影响的只要一种就是当余额够时选不选
            // dP就是后面状态依存前面状态，前面状态被后面状态调用
        }
        /*
        好神奇的是写成这样只得46分
        for(int j=n;j>=0;j--)
        {
            if(j>=a[i])
            {
                f[j]=f[j]+f[j-a[i]];
            }
        }
        */
    }
    cout << f[n] << endl;
    return 0;
}