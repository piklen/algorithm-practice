#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int q[N];
int n, m;
int find(int x)
{
    if (q[x] != x) //找到根节点，根节点它自己等于自己
    {
        q[x] = find(q[x]);
    }
    return q[x];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        q[i] = i;
    }
    while (m--)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'M')
        {
            q[find(a)] = find(b); //合并集合
        }
        else
        {
            if (find(a) == find(b))
            {
                cout << "Yes" << endl; //进行判断，如果根节点相等就进行输出
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
//查交并集关键进行状态压缩
/*
 if (q[x] != x)//找到根节点，根节点它自己等于自己
    {
        q[x] = find(q[x]);
    }
*/