#include <iostream>
using namespace std;
void fuc(int *q, int *p, int *k)
{
    int temp;
    if (*q > *p)
    {
        temp = *q;
        *q = *p;
        *p = temp;
    }
    if (*q > *k)
    {
        temp = *q;
        *q = *k;
        *k = temp;
    }
    if (*p > *k)
    {
        temp = *p;
        *p = *k;
        *k = temp;
    }
    return;
}
int main()
{
    int a, b, c;
    int *q, *p, *k;
    cin >> a >> b >> c;
    q = &a;
    p = &b;
    k = &c;
    fuc(q, p, k);
    cout << a << " " << b << " " << c;
    return 0;
}
