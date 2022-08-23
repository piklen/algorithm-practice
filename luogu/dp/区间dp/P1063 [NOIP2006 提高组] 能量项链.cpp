#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 210;
int n;
int a[N], f[N][N];
const int INF = 0x7fffffff;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    //进行核心代码书写
    for (int len = 3; len <= n + 1; len++) //长度限制,长度为3，也就是下标间距为3实际只完整包含了两个棋子的信息
    {
        for (int i = 1; i + len - 1 <= 2 * n; i++) //左端点，以及总长度为n
        {
            //右端点
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++) //这里k的开始要是i+1，因为需要三个点，才能构建成两颗能量球
            {
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]); //他们是连续的，不同于石子合并
            }
        }
    }
    //找出最大值
    int maxx = -INF;
    for (int i = 1; i <= n; i++)
    {
        maxx = max(maxx, f[i][i + n]);
    }
    cout << maxx << endl;
    return 0;
}