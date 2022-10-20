#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int len;
int a[5010] = {1}, b[5010] = {1}, c[5010] = {1}; //初始化，a,b,c均为1
void func()
{
    int flag = 0;
    for (int i = 0; i < len; i++) //高精度加法计算
    {
        c[i] = a[i] + b[i] + flag;
        flag = c[i] / 10;
        c[i] %= 10;
    }
    //进位
    if (flag)
    {
        c[len] = flag;
        len++;
    }
    //进行斐波那契数列计算
    for (int i = 0; i < len; i++)
    {
        a[i] = b[i];
        b[i] = c[i];
    }
}
int main()
{
    int n;
    cin >> n;
    len = 1;
    for (int i = 2; i <= n; i++)
    {
        func();
    }
    for (int i = len - 1; i >= 0; i--)
    {
        cout << c[i];
    }
    cout << endl;
    return 0;
}
/*
1.由题意可以知道他其实是一个斐波那契数列+高精度，分别进行处理就好了

*/
