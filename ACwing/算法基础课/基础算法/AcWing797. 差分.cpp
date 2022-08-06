#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int b[N];
void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        insert(i, i, x);
    }
    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
        //相当于
        /*
        b[i]=a[i]-a[i-1];
        */
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + b[i];
        cout << b[i] << " ";
    }
    return 0;
}
//差分的前缀和就是原数组值，在也可以用一个insert函数来少一个数组的使用