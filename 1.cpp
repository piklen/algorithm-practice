#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int w[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        w[i] = i;
    }
    sort(w + 1, w + 1 + n, [](int a, int b)
         { int s1 = 0, s2 = 0, x = a, y = b;
         while(x){
             s1 += (x % 10);
             x /= 10;
         } 
         while(y){
             s2 += (y % 10);
             y /= 10;
         } 
         if(s1!=s2)
         {
             return s1 < s2;
         }
         return a<b; });
    cout << w[m] << endl;
    return 0;
}