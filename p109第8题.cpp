#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int maxx = 0;
    maxx = max(max(a, b), c);
    cout << maxx << endl;
    return 0;
}