#include <iostream>
using namespace std;
const int N = 2e5 + 10;
long long date[N], s[N];
int main()
{
    int n, k;
    cin >> n;
    int ff = 0; //以ff为全局的时间顺序栈
    for (int i = 1; i <= n; i++)
    {
        cin >> date[i];
        s[++ff] = i;
    }
    cin >> k;
    int x = 0;
    for (int i = 1; i <= k; i++)
    {
        int a, b, c;
        cin >> a;
        if (a == 1)
        {
            cin >> x;  //并且存下这个全局赋值的
            while (ff) //这一步第一次做的比较多，后面都比较少
            {
                date[s[ff--]] = 0; // s[ff]里面存的是i
            }
        }
        else if (a == 2)
        {
            cin >> b >> c;
            date[b] += c;
            s[++ff] = b; //这个只是进行时间顺序的标记
        }
        else
        {
            cin >> b;
            cout << date[b] + x << endl;
        }
    }
    return 0;
}
//关键点在实现了O(N)，有栈的思想