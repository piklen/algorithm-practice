#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 40;
int v[N], w[N];
int f[30100];
int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++) // n个物品进行输入
    {
        cin >> v[i] >> w[i];
        w[i] *= v[i]; //要使得权值最大，在这个题目中权值为乘积
    }
    for (int i = 1; i <= n; i++) // n个物品分别进行选与不选的判断
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]); //每一个可以选择的都进行和已有的max做比较，选出较大的哪一个
        }
    }
    cout << f[m] << endl;
    return 0;
}