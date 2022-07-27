#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 220;
int c[N];
bool st[N];
int main()
{
    int g[N][N];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true; //表示这两位有联系
    }
    //进行关系判断读入
    int s = 0;
    cin >> s;
    for (int T = 1; T <= s; T++)
    {
        int mm;
        cin >> mm;
        memset(c, 0, sizeof c);
        memset(st, 0, sizeof st); //用这个数组来标记存数
        for (int i = 1; i <= mm; i++)
        {
            cin >> c[i];
            st[c[i]] = true; //注意标记的是数组里面的值，不是i
        }
        //判断数组内是否两两互为好友
        bool flag = true;
        for (int i = 1; i <= mm; i++)
        {
            for (int j = i + 1; j <= mm; j++)
            {
                if (!g[c[i]][c[j]]) //是存下来的数组内的值进行比较
                {
                    flag = false;
                }
            }
        }
        if (!flag) //如果区域内有不是好友的，就进行输出，然后这个判断结束
        {
            printf("Area %d needs help.\n", T);
            continue;
        }
        else //找到区域内是否和其他人还有联系
        {
            int id = 0;
            for (int i = 1; i <= n; i++)
            {
                bool flag = true;
                if (!st[i]) //还没有判断过的人
                {
                    for (int j = 1; j <= mm; j++)
                    {
                        if (!g[i][c[j]]) //如果选择的这个人和区域内的人有不认识的就结束这一次循环
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) //如果没有进入上一个循环，就说明他与全部已经在区域内的人是好友关系
                    {
                        id = i;
                        break; //选出最小的那个就好了
                    }
                }
            }
            if (id) //如果id不为0就说明有人满足在区域外与这一区域的人全为好友
            {
                printf("Area %d may invite more people, such as %d.\n", T, id);
            }
            else
            {
                printf("Area %d is OK.\n", T);
            }
        }
    }
    return 0;
}