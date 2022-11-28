#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d; //使x⋅y能被a⋅b整除意思是？（a*b)%(x*y)==0?
        bool flag = false;
        for (long long i = a + 1; i <= c; i++)
        {
            long long k = gcd(a * b, i);
            long long y = a * b / k; //这两个步骤保证了a*b>x*y;
            //也就是x*y是a*b的一个因子
            y = (y + b) / y * y; //这个操作，保证了y>b,当y>b时算出的是y，当y<b时算出的是n*y>b例如：（2+4）/2*2;
            if (y <= d)
            {
                cout << i << " " << y << endl;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            cout << "-1 -1" << endl;
        }
    }
    return 0;
}