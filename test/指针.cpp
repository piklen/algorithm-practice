#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int *p = new int(10);
    int &a = *p;
    if (!(*p))
    {
        cout << "ÉêÇëÄÚ´æÊ§°Ü£¡" << endl;
    }
    if (*p)
    {
        cout << "ÉêÇëÄÚ´æ³É¹¦" << endl;
        cout << *p << endl;
        cout << a << endl;
        cout << &a << endl;
        cout << &(*p) << endl;
        cout << &(p) << endl;
        cout << p << endl;
    }
    return 0;
}