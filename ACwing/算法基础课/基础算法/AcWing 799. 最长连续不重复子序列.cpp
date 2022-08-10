#include <iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N], s[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    for (int i = 0, j = 0; i < n; i++)//设置两个指针i,j，使得i在前，j来判断不重复区间长度
    {
        s[a[i]]++;//统计每一个数字出现的次数
        while (s[a[i]] > 1)//当出现次数大于两次，说明有重复的数字出现了
        {
            s[a[j]]--;//j指针进行移动
            j++;
        }
        res = max(res, i - j + 1);//每个i都进行统计一次在i与j之间有多少不重复的数字
    }
    cout << res << endl;
    return 0;
}
//使用双指针算法，双指针的出现一般是为了简化时间复杂度，由暴力的O(N^2)减到O(n),这个题目就是典型的这种做法