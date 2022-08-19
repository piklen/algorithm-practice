//拉链法
/*
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100003;//这个N定义成大于所需数据的第一个质数
int e[N], h[N], nx[N], idx;
void insert(int x)
{
    int t = (x % N + N) % N;//mod取余，这样做可以实现负数取余
    e[idx] = x;//链表的形式进行存储
    nx[idx] = h[t];
    h[t] = idx;
    idx++;
}
bool finf(int x)
{
    int t = (x % N + N) % N;
    for (int i = h[t]; i != -1; i = nx[i])//在链表里面查找，找到就return true
    {
        if (e[i] == x)
        {
            return true;
        }
    }
    return false;//没有找到就return FALSE
}
int main()
{
    int n;
    cin >> n;
    memset(h, -1, sizeof(h));//链表初始化为-1
    while (n--)
    {
        string s;
        cin >> s;
        int x;
        if (s == "I")
        {
            cin >> x;
            insert(x);
        }
        else
        {
            cin >> x;
            if (find(x))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
*/
//拉链法就是先找到哪个余数，然后在余数之后构造链表
//开放寻址法
#include <iostream>
#include <cstring>
using namespace std;
const int N = 200003, null = 0x3f3f3f3f;//N的取值在数据的2~3倍的第一个质数，然后数组初始化为一个数据范围之外的数
int h[N];
int finf(int x)
{
    int t = (x % N + N) % N;
    while (h[t] != null && h[t] != x)//如果这个余数不为空，并且这里面的数不是要找的哪个数，就一直往后找
    {
        t++;
        if (t == N)//到了数组的最后一个，就回到开头继续找
        {
            t = 0;
        }
    }
    return t;//返回值，如果找到就返回数组下标，没有找到就返回下标值内为null的值
}
int main()
{
    int n;
    cin >> n;
    memset(h, 0x3f3f3f3f, sizeof(h));
    while (n--)
    {
        string s;
        cin >> s;
        int x;
        cin >> x;
        int k = find(x);
        if (s == "I")
        {
            h[k] = x;//h[k]开始时为null然后把x进行赋值
        }
        else
        {
            if (h[k] != null)//如果这个返回的下标里面的值不为空，那么就说明找到了
            {
                cout << "Yes" << endl;
            }
            else//不然就是没有找到
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}