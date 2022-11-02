#include <iostream>
using namespace std;
void LinkChar(char a[], char b[])
{
    char c[100];
    int cnt = 0;
    for (int i = 0;; i++)
    {
        if (!a[i])
        {
            break;
        }
        c[cnt++] = a[i];
        }
    for (int i = 0;; i++)
    {

        if (!b[i])
        {
            break;
        }
        c[cnt++] = b[i];
    }
    cout << c << endl;
    return;
}
int main()
{
    char a[50];
    char b[50];
    cin >> a >> b;
    LinkChar(a, b);
    return 0;
}