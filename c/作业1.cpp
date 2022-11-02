#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a % b != 0)
    {
        return gcd(b, a % b);
    }
    return b;
}
int main()
{
    int a, b;
    cout << "请输入任意两个正整数：" << endl;
    cin >> a >> b;
    int c = gcd(a, b);
    printf("%d与%d的最大公约数是%d\n", a, b, c);
    printf("%d与%d的最小公倍数是%d\n", a, b, a * b / c);
    return 0;
}