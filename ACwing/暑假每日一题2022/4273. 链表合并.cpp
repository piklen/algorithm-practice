#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10;
typedef pair<int, int> PII;
int nx[N], v[N];
int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    while (n--) //进行数据的读入
    {
        int add, val, next;
        cin >> add >> val >> next;
        v[add] = val;
        nx[add] = next;
    }
    //进行链表的构造
    vector<PII> A, B;
    for (int i = a; i != -1; i = nx[i])
    {
        A.push_back({i, v[i]});
    }
    for (int i = b; i != -1; i = nx[i])
    {
        B.push_back({i, v[i]});
    }
    if (A.size() < B.size()) //使得A链表最长
    {
        swap(A, B);
    }
    vector<PII> C; //合并成一条链表
    for (int i = 0, j = B.size() - 1; i < A.size(); i += 2, j--)
    {
        C.push_back(A[i]);
        if (i + 1 < A.size())
        {
            C.push_back(A[i + 1]);
        }
        if (j >= 0)
        {
            C.push_back(B[j]);
        }
    }
    //进行C链表的输出
    for (int i = 0; i < C.size(); i++)
    {
        printf("%05d %d", C[i].x, C[i].y);
        if (i + 1 < C.size())
        {
            printf(" %05d\n", C[i + 1].x);
        }
        else
        {
            cout << " -1" << endl;
        }
    }
    return 0;
}
//学习到的知识点
// 1.define以及typedef的使用，用于重定义
// 2.pair的使用，就是将两个数据变成一组数据来使用
// 3.对于链表，在算法题目中一般不直接写链表结构，而是使用数组来存储，一个数组存data一个数组存next做指针数组
// 4.vector可以存pair，pair的调用是用first以及second来做的
