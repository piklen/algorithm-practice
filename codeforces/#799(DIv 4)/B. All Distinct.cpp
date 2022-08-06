#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        set<int> s1;
        int n;
        cin >> n;
        int x;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            s1.insert(x);
        }
        int x1 = n % 2, x2 = s1.size() % 2; //判断奇偶性，偶数减偶数等于偶数，奇数减奇数等于偶数，刚好是2的倍数，不然到最后就会剩下一个数相同的数量必然是2所以要带走一个只有有一个数量的数
        if (x1 == x2)
        {
            cout << s1.size() << endl;
        }
        else
        {
            cout << s1.size() - 1 << endl;
        }
    }
    return 0;
}