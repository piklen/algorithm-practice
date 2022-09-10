#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double a[1010];
int main()
{
    double n;
    cin >> n;
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum = sum / n;
    double cnt = 0.0;
    for (int i = 0; i < n; i++)
    {
        cnt = cnt + fabs(a[i] - sum) * fabs(a[i] - sum);
    }
    cnt = cnt / n;
    cnt = sqrt(cnt);
    for (int i = 0; i < n; i++)
    {
        printf("%.16f\n", (a[i] - sum) / cnt);
    }
    return 0;
}
//简单的算术题，刚开始出错是因为算标准差时算到了n这也告诉我，在检查代码时，只要感觉逻辑不正确，就应该多看看循环部分循环了多少次