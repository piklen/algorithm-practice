#include <iostream>
using namespace std;
int main()
{
    char *pch1, *pch2;
    pch1 = new char;
    pch2 = pch1;
    *pch2 = 'B';
    delete pch1;
    pch1 = NULL;
    cout << pch2 << endl;
    delete pch2;
    pch2 = NULL;
    cout << pch2 << endl;
    return 0;
}
