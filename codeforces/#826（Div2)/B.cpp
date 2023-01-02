#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2) // 奇数个相同的数相互异或最后还是为自己
        {
            while (n--)
            {
                cout << "1 ";
            }
            cout << endl;
        }
        else
        {
            cout << "1 3 "; // 先找到最小的两个数符合条件的
            n -= 2;
            while (n--)
            {
                cout << "2 "; // 再把偶数个相互异或，最后值为0
            }
            cout << endl;
        }
    }
    return 0;
}