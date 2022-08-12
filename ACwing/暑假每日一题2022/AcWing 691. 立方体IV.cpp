#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int N = 1010;
int n;
int w[N][N], f[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //坐标对照，顺序是上右下左
int dp(int x, int y)
{
    int &v = f[x][y]; // v取出了，f[x][y]中的值，并且修改了v会对f[x][y]进行修改
    if (v != -1)      //如果已经被计算过了，那么就调用之前计算的状态
    {
        return v;
    }
    v = 1; //没有被遍历过，最少都是自己哪一格
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];                                 //坐标变化,x,y是同步变化的
        if (a >= 0 && a < n && b >= 0 && b < n && w[a][b] == w[x][y] + 1) //进行合法性判断，不越界并且满足题目要求
        {
            v = max(v, dp(a, b) + 1); //取当前值，或者能够移动后的最大值
        }
    }
    return v;
}
int main()
{
    int t;
    cin >> t;
    for (int Case = 1; Case <= t; Case++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> w[i][j];
            }
        }
        memset(f, -1, sizeof(f)); //每一次t都进行初始化
        int id = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = dp(i, j);
                if (temp > cnt || (temp == cnt && (id > w[i][j]))) //如果i,j这个坐标能够走的长度大于当前长度，
                //或者等于当前长度，但是i,j坐标存储的值要小于之前相同长度存储的值，就进行更新
                {
                    cnt = temp;
                    id = w[i][j];
                }
            }
        }
        cout << "Case #" << Case << ": " << id << " " << cnt << endl;
    }
    return 0;
}
// dp,记忆化储存，贪心的综合运用，利用dp进行状态存储，减少运算次数