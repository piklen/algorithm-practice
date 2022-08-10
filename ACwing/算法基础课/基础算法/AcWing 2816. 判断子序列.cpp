#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        if (j < n && b[i] == a[j]) //特例判断
        {
            j++;
        }
    }
    if (j == n)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
//双指针，由题目所知，所给数据都是单调递增的，所以可以当相等时进行另一指针移动，但是有一个特例
/*
1 2
1
1 0
*/
//因为数组初始化时为0，所以要加上判断条件，j指针只能小于等于n，在循环时要小于n