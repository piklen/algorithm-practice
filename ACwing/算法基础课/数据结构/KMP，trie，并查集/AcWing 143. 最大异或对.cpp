#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int idx = 0;
int son[31 * N][2];
void insert(int x)//插入操作
{
    int q = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;//进行二进制取到每一位
        if (!son[q][u])//如果取到的这个位置不存在
        {
            son[q][u] = ++idx;//新建这个位置并且存值
        }
        q = son[q][u]; // 不能写成q = idx;因为如果不进++idx哪一步会使得q值一直取存在的，如果两边都存在，那么可能会出错
    }
}
int query(int x)//查询操作
{
    int q = 0;
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[q][!u])//如果存在相反值，那么就用相反的那个，因为异或性质
        {
            res = res * 2 + !u;//二进制左移刚好那个数复原
            q = son[q][!u];//存储数据
        }
        else
        {
            res = res * 2 + u;//优先考虑的是出现相反的，如果没有出现相反的，那么只能将就
            q = son[q][u];
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(x);//先插入后查询
        int t = query(x);
        res = max(res, t ^ x);//查询这个数之前的一个数使得与这个值异或取值最大
    }
    cout << res << endl;
    return 0;
}
//trie树来实现数字的二进制分解，刚好异或运算的性质为同为0不同为1