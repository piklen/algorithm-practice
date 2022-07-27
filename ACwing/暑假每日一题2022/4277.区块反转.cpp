#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int da[N], nx[N], q[N];
int main()
{
    int h, n, m;
    cin >> h >> n >> m;
    for (int i = 0; i < n; i++) //读入链表
    {
        int add, data, next;
        cin >> add >> data >> next;
        da[add] = data;
        nx[add] = next;
    }
    int cnt = 0;
    //构建链表，并读取总数据
    for (int i = h; i != -1; i = nx[i]) //现在的i中存储的是链表地址
    {
        q[cnt++] = i;
    }
    reverse(q, q + cnt); //先进行全部反过来，再分段进行处理
    //分片区进行反转，i+1是片段内最后一个元素在整个数组中排第几，max(0,i-m+1)很好的避免了取到负数的情况，也就是最后一个单元组还有几个就几个进行反转就好了
    for (int i = cnt - 1; i >= 0; i -= m)
    {
        reverse(q + max(0, i - m + 1), q + i + 1); //核心算法步骤
    }
    //进行输出
    for (int i = 0; i < cnt; i++)
    {
        printf("%05d %d ", q[i], da[q[i]]);
        if (i == cnt - 1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%05d\n", q[i + 1]);
        }
    }
    return 0;
}
/*
1.进行链表的区块反转，有这样一种思路，就是先进行全部链表反转，再进行部分链表进行反转
2.理解reverse函数，是进行区间内函数反转，可以用于数组也可以用于字符串
3.链表题的基本操作就是读入用数组进行存储，下标当做地址
*/
