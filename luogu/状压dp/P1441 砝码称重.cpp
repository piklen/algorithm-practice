#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, ans = 0, last;
const int N = 30;
int a[N];
bool flag[N], f[2100]; //最大砝码质量为20*100
void dfs(int u)
{
    if (u == m + 1) //表示不选m个的那一次状态，因为进入这个循环时，只有m个标记了为不选
    {
        memset(f, 0, sizeof(f));
        int cnt = 0;
        f[0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (!flag[i]) //为TRUE表示这个数组不选，默认是FALSE
            {
                for (int j = 2000; j >= a[i]; j--)
                {
                    f[j] |= f[j - a[i]]; //或运算，有一个为TRUE表示存在这个方案
                    // f[j-a[i]]==TRUE表示存在一个方案它能组成的容量是j-a[i]
                    //  f[j]=(f[j]||f[j-a[i]]);
                }
            }
        }
        for (int i = 1; i <= 2000; i++) //是到2000并不是到n，表示两千内所以可能的状态
        {
            if (f[i]) //如果存在这个状态就加一
            {
                cnt++;
            }
        }
        ans = max(ans, cnt); //看不选m个砝码中最大的一种组成是什么
        return;
    }
    for (int i = last + 1; i <= n; i++) //枚举从1到n中所有少选m个砝码的方案
    {
        flag[i] = true; // flag为TRUE表示这个砝码不选
        last = i;       //维持给下一个状态
        dfs(u + 1);
        flag[i] = false; //一遍结束，重回状态
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}