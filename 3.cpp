#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        int maxx = 0;
        cin >> a >> b >> c;
        maxx = max(a, b);
        maxx = max(maxx, c);
        if (maxx == a && maxx == b && maxx == c) //相等
        {
            cout << a + 1 << " " << a + 1 << " " << a + 1 << endl;
        }
        else //不相等
        {

            if (maxx == a && maxx == b)
            {
                cout << "1"
                     << " "
                     << "1"
                     << " " << maxx - c + 1 << endl;
            }
            else if (maxx == b && maxx == c)
            {
                cout << maxx - a + 1 << " 1 1" << endl;
            }
            else if (maxx == a && maxx == c)
            {
                cout << "1 " << maxx - b + 1 << " 1" << endl;
            }
            else if (maxx == a)
            {
                cout << "0"
                     << " " << maxx - b + 1 << " " << maxx - c + 1 << endl;
            }
            else if (maxx == b)
            {
                cout << maxx - a + 1 << " "
                     << "0"
                     << " " << maxx - c + 1 << endl;
            }
            else
            {
                cout << maxx - a + 1 << " "
                     << maxx - b + 1
                     << " "
                     << "0" << endl;
            }
        }
    }

    return 0;
}