#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> A, B, C;
vector<int> add(vector<int> &A, vector<int> &B) //注意这里有取地址符，就是用的全局定义的那个动态数组
{
    int t = 0;                                         //用来进位
    for (int i = 0; i < A.size() || i < B.size(); i++) //最短的先加完
    {
        if (i < A.size())
        {
            t += A[i];
        }
        if (i < B.size())
        {
            t += B[i];
        }
        C.push_back(t % 10);
        t /= 10; //取大于十的部分
    }
    if (t) //如果不为零说明首位是进位
    {
        C.push_back(1); //那么就加一
    }
    return C; //vector类型的返回值
}
int main()
{
    string a, b;
    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0'); //逆序存储
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }
    return 0;
}
//高精度加法，使用vector这个动态数组，先进行逆序存储，注意进位就好了