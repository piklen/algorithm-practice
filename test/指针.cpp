#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int *p = new int(10);
    int &a = *p;
    if (!(*p))
    {
        cout << "�����ڴ�ʧ�ܣ�" << endl;
    }
    if (*p)
    {
        cout << "�����ڴ�ɹ�" << endl;
        cout << *p << endl;
        cout << a << endl;
        cout << &a << endl;
        cout << &(*p) << endl;
        cout << &(p) << endl;
        cout << p << endl;
    }
    return 0;
}