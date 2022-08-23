#include <iostream>
using namespace std;
int a[10];
bool b[10];
int n;
void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!b[i]) //状态判断
        {
            a[x] = i;
            b[i] = true; //状态修改
            dfs(x + 1);
            b[i] = false; //状态恢复
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
// dfs首先要理解他是一个递归加回溯的的东西，需要的过程有递归判断，状态恢复，结果判断，我们需要找到的是它是满足某一个问题的一个集合
