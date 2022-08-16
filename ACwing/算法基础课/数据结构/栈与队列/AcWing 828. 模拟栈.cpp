#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;
    int tt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            cin >> a[++tt]; //入栈，因为tt初始化时为0所以要++tt;
        }
        else if (s == "query")
        {
            cout << a[tt] << endl; //查询栈顶元素
        }
        else if (s == "empty")
        {
            if (tt) //如果tt不为0就说明栈不为空
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
        else
        {
            tt--; //栈顶元素出栈，就直接指针移动就好了
        }
    }
    return 0;
}
//用数组实现栈，需要选定一个指针tt,数组存值从1号下标开始