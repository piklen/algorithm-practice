#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int q[N], tt = -1, hh;//tt表示队尾，hh表示队头
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "push")//入队操作
        {
            cin >> q[++tt]; //因为tt初始化为-1.所以要写成++tt，如果初始化为0，那么写成tt++;
        }
        else if (s == "query")
        {
            cout << q[hh] << endl;//查询队头操作
        }
        else if (s == "pop")//删除队头
        {
            hh++;
        }
        else
        {
            if (hh <= tt)//判断队列是否为空，如果队头大于队尾那么就是空
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
//用数组模拟队列