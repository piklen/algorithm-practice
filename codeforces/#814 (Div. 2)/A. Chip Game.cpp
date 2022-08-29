#include <iostream>
#include <cstdio>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if ((a + b) % 2)
        {
            printf("Burenka\n");
        }
        else
        {
            printf("Tonya\n");
        }
    }
    return 0;
}