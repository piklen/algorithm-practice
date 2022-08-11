#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
cosnt int N = 1e5 + 10;
vector<pair<int, int>> a, b;
vector<pair<int, int>> merge(vector<pair<int, int>> &a)
{
    sort(a.begin(), a.end());//进行排序，排序的依据是先进行first然后再second
    int be = -2e9, ed = -2e9;//虚拟初始化一个区间，这个区间要在所给范围的前面
    for (auto i : a)
    {
        if (ed < i.first)//如果前一个区间的末尾小于后一个区间的头，那么说明这一个区间结束了
        {
            if (be != -2e9)//如果不是初始化的那个区间，就进行存储
            {
                b.push_back({be, ed});
            }
            be = i.first;//进行区间的前进
            ed = i.second;
        }
        else//如果前一个区间的末尾大于后一个区间的开头，那么就有两种情况，一种是前一个区间的末尾要大，另一种是后一个区间的末尾要大，取较大的哪一个
        {
            ed = max(ed, i.second);
        }
    }
    if (be != -2e9)
    {
        b.push_back({be, ed});//处理最后一个区间，如果最后哪个区间不为虚拟区间，就进行添加区间
    }
    return b;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r});//输入数据
    }
    merge(a);
    cout << b.size() << endl;
    return 0;
}
//区间合并，利用vector以及pair进行存储数据，然后对头进行排序，然后进行线段的扫描