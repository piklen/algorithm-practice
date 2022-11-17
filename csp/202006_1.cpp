#include <iostream>
using namespace std;
struct ss
{
    long long a, b;
    char c;
} cc[10010];
int main()
{
    long long n, m;
    cin >> n >> m;
    long long A = 0, B = 0;
    for (long long i = 1; i <= n; i++)
    {
        long long a, b;
        char c;
        cin >> a;
        cin >> b;
        cin >> c;
        cc[i].a = a, cc[i].b = b, cc[i].c = c;
    }
    while (m--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long up = 0;
        bool flag = true;
        for (long long i = 1; i <= n; i++)
        {
            long long ansa = 0;
            long long ansb = 0;
            long long ans = 0;
            if (cc[i].c == 'A' && up == 0) //先进行两次状态标记
            {
                ansa = cc[i].a * b + cc[i].b * c + a;
                if (ansa > 0)
                {
                    up = 'A';
                }
                else
                {
                    up = 'B';
                }
            }
            else if (cc[i].c == 'B' && up == 0)
            {
                ansb = cc[i].a * b + cc[i].b * c + a;
                if (ansb > 0)
                {
                    up = 'B';
                }
                else
                {
                    up = 'A';
                }
            }
            else
            {
                ans = cc[i].a * b + cc[i].b * c + a;
                if (ans > 0) //再根据这个状态进行对比
                {
                    if ((cc[i].c == 'A' && up == 'A') || (cc[i].c == 'B' && up == 'B'))
                    {
                        continue;
                    }
                    else
                    {
                        cout << "No" << endl;
                        flag = false;
                        break;
                    }
                }
                else
                {
                    if ((cc[i].c == 'A' && up == 'B') || (cc[i].c == 'B' && up == 'A'))
                    {
                        continue; //不加continue在ACwing上会报错
                    }
                    else
                    {
                        cout << "No" << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}
//总体思路就是先进行标记，再进行判断，先标记可以使用一个变量来存，在这里是up