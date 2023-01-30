#include <iostream>
using namespace std;
int main()
{
    for (int i = 4; i <= 4; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << "i:" << i << "  j:" << j << "   i^j:" << (i ^ j) << endl;
        }
    }
    return 0;
}