#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int num = a * 100 + b;
    for (int i = num;; i++)
    {
        int h, m;
        h = (i / 100) % 10;
        m = (i % 100) / 10;
        a = (i / 1000) * 10 + m;
        b = h * 10 + i % 10;
        if ((a <= 23) && (b <= 59))
        {
            cout << i / 100 << " " << i % 100 << endl;
            break;
        }
        if (i == 2359)
        {
            i = -1;
        }
    }
    return 0;
}