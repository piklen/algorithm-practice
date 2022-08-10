#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }
    int j = m - 1;
    for (int i = 0; i < n; i++)
    {
        while (j >= 0 && a[i] + b[j] > k) // a数组从前往后遍历，b数组从后往前遍历，当和大于x时，a以后数组加b一定大于x所以，b可以减小
        {
            j--; //移动b数组的指针
        }
        if (a[i] + b[j] == k) //因为题目说了，只出现一个
        {
            cout << i << " " << j << endl;
            break;
        }
    }
    return 0;
}
//双指针算法，观察双指针我们发现，他们都是有单调性的，a,b数组都是单调递增的，
//于是可以证明当a去最小时，b取最大时的和大于所求的数时a往后的数加上b都会使得大于所求数，所以b要减小