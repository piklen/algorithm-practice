#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5010;
int main()
{
    string a = "POSSIBLE";
    string b = "IMPOSSIBLE";
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int sum = 0;
        sum = n * (n + 1) / 2; //等差数列的公式
        int c = x + y;
        if (sum % c == 0)
        {
            cout << "Case #" << i << ": " << a << endl;
            //怎么做到选一些数等于这个数？
            //利用贪心，从后向前
            int ans[N] = {};
            int A = sum / c * x; //按比例算出所需要的和
            int cnt = 0;
            for (int j = n; j >= 1; j--)
            {
                if (j <= A) //从后向前，不断选择需要的数值，这种方法很好的避免了从前向后的不确定性
                {
                    ans[cnt++] = j;
                    A -= j;
                }
            }
            cout << cnt << endl;
            for (int j = 0; j < cnt; j++)
            {
                if (j == cnt - 1)
                {
                    cout << ans[j] << endl;
                }
                else
                {
                    cout << ans[j] << " ";
                }
            }
        }
        else
        {
            cout << "Case #" << i << ": " << b << endl;
        }
    }
    return 0;
}
//学习要求一个数是由那些数组成的，其中一个方法就是从后向前，不断减小，其实在无序数列中也可以，先进行排序后从后到前进行计算