#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        int alen = a.size();
        a += a;
        string c;
        cin >> c;
        int clen = c.size();
        bool flag = false;
        for (int i = 0; i < alen; i++)
        {
            int aa = i, cc = 0;
            while ((aa < alen + i) && (cc < clen)) // 以这个点来循环一圈
            {
                if (a[aa] == c[cc])
                {
                    aa++;
                    cc++;
                }
                else
                {
                    aa++;
                }
                if (cc == clen)
                {
                    cout << "Y" << endl;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (!flag)
        {
            cout << "N" << endl;
        }
    }
    return 0;
}