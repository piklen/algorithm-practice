#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int aa = 1;
    int sum = 0;
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            sum += aa * (a[i] - '0');
            aa++;
        }
    }
    if (sum % 11 < 10)
    {
        if (sum % 11 == (a[12] - '0'))
        {
            cout << "Right" << endl;
        }
        else
        {
            a[12] = (sum % 11) + '0';
            cout << a << endl;
        }
    }
    else
    {
        if (a[12] == 'X')
        {
            cout << "Right" << endl;
        }
        else
        {
            a[12] = 'X';
            cout << a << endl;
        }
    }
    return 0;
}