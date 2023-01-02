#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        if (n % x != 0) // 如果不能把n放在x的位置，则不能符合中间那个倍数的条件
        {
            cout << "-1" << endl;
        }
        else // 如果可以，则要考虑n是不是放的太前了
        {
            for (int i = 1; i < n; i++)
            {
                a[i] = i;
            }
            a[x] = n;
            a[1] = x;
            a[n] = 1; // 这一串的书写可以参考输入n==2,x==1，期盼输出的应该是1 1，从而来确定顺序
            int temp = x;
            for (int i = 1; i * x < n; i++) // 把所有x的倍数的位置都进行遍历
            {
                if ((i * x) % temp == 0 && n % (x * i) == 0) // 如果x这个位置能能被下一个x的倍数位置上的数进行整除，并且n能整除下一个x倍数上的数时就进行交换
                {
                    int t = a[temp];
                    a[temp] = a[i * x];
                    a[i * x] = t;
                    temp = i * x;
                }
            }
            for (int i = 1; i <= n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}