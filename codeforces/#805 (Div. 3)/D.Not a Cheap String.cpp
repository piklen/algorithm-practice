#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int flag[200];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(flag, 0, sizeof(flag));
        string b;
        int m;
        cin >> b >> m;
        int sum = 0;
        int cnt = 0;
        int ss = 0;
        for (int i = 0; i < b.size(); i++)
        {
            flag[b[i]]++;          //储存每一个数的数量
            sum += b[i] - 'a' + 1; //相对总和
        }
        if (sum <= m)
        {
            cout << b << endl;
            continue;
        }
        else
        {
            for (int i = 122; i >= 97; i--) //题目要求从大到小进行去除
            {
                if (sum <= m)
                {
                    break;
                }
                else
                {
                    while (flag[i] && sum > m) //如果这个字母在这个字符串中还有并且总和还没有满足条件，就进行数量上的减一
                    {
                        sum -= (i - 'a' + 1);
                        flag[i]--; //这个字母的数量进行减一
                    }
                }
            }
            for (int i = 0; i < b.size(); i++)
            {
                if (flag[b[i]]) //从字符串开端进行输出，如果这个字符还有数量，就进行减一
                {
                    cout << b[i];
                    flag[b[i]]--;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
//主要学习如何实现字符串的按条件消除操作，是把每个字符进行数字上的统计，分别进行处理