#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int l, r;
    string a;
    cin >> a;
    int len = a.size();
    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < len - i; j++)
        {
            l = j, r = i + j;
            while (a[l] == a[r])
            {
                l++, r--;
            }
            if (r <= l)
            {
                for (int k = j; k <= i + j; k++)
                {
                    cout << a[k];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
