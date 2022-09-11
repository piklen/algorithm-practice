#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n, k;
    cin >> n >> k;
    a[0] = 1;
    int ans = 0;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (a[y] != 0)
        {
            a[x] = 1;
        }
        else
        {
            a[x] = 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
//简单的逻辑题，就是先判定右边有赋值过没，没有的话就答案加一然后把左值进行赋值