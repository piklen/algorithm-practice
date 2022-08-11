#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
int a[N], sum[N];
vector<pair<int, int>> add, query;
vector<int> alls;
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (alls[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r + 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c}); //先进行插入
        alls.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r}); //把查询的坐标也放进去
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());                           //排序，离散化后的排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end()); //保持唯一性
    for (auto item : add)
    {
        int x = find(item.first); //返回的是item.first这个值在整个alls中的下标位置
        a[x] += item.second;      //找到这个下标，用a[]来对alls进行映射
    }
    for (int i = 1; i <= alls.size(); i++)
    {
        sum[i] = sum[i - 1] + a[i]; //下标进行前缀和
    }
    for (auto item : query) //对查询的vector数组进行遍历
    {
        int l = find(item.first); //找到在allls中对应的下标
        int r = find(item.second);
        cout << sum[r] - sum[l - 1] << endl; //映射出来的前缀和进行计算
    }
    return 0;
}
//离散化，求数据，离散化的原因是因为数据的值域很大，然而数据量不是很大的情况基本思路就是先排序，再去重，再查找对数据进行处理