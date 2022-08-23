#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
int f[N], a[N];
int sum = 1, n;
int b[7] = {0, 1, 2, 3, 5, 10, 20};
int main()
{
    for (int i = 1; i <= 6; i++)
    {
        cin >> n;
        for (int j = 1; j <= n; j++)
        {
            a[sum++] = b[i]; //把每一个砝码的质量存储到a[i]数组里面去，然后不停的到后面调用
        }
    }
    f[0] = 1;                      //把质量为0这个状态设置为存在，也就是砝码全不选
    for (int i = 1; i <= sum; i++) //枚举每一个砝码，在已有的质量里面的变化，主要这个砝码现在是单面的，也就是只在一边存在或者不存在，所以可以用这种去枚举
    {
        for (int j = 1000; j >= 0; j--) //最大质量题目已经给了，如果没有给自己可以求
        {
            if (f[j]) //如果j这个质量是存在的，那么j+a[i]这个质量也是一定存在的，将其设置为1
            {
                f[j + a[i]] = 1; //把这个质量设置为1
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 1000; i++) //遍历每一个质量，存在则ans++
    {
        if (f[i])
        {
            ans++;
        }
    }
    cout << "Total=" << ans << endl;
    return 0;
}
