#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
struct Data
{
    int a;
    int b;
} dat[N];
bool cmp(Data x, Data y)
{
    if (x.b != y.b)
    {
        return x.b < y.b;
    }
    return x.a < y.a;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        int sum = 0;
        while (temp)
        {
            sum += (temp % 10);
            temp /= 10;
        }
        dat[i].a = i;
        dat[i].b = sum;
    }
    sort(dat + 1, dat + n + 1, cmp);
    cout << dat[m].a << endl;
    return 0;
}