#include <iostream>
#include <algorithm>
using namespace std;
int a[10010];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int maxx = 0;
    int maxi;
    for (int i = 0; i <= 10000; i++)
    {
        if (a[i] > maxx)
        {
            maxx = a[i];
            maxi = i;
        }
    }
    cout << maxi << endl;
    return 0;
}