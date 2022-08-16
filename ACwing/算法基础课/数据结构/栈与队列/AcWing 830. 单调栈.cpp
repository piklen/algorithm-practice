#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int s[N];
int tt = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {

        int x;
        cin >> x;
        while (tt && s[tt] >= x) //如果栈里面有数，并且数值大于等于插入的这个数，那么就把那些数出栈
        {
            tt--;
        }
        if (tt) //如果栈里面有数，那么栈顶就是要求的那个函数
        {
            cout << s[tt] << " ";
        }
        else
        {
            cout << "-1 "; //栈里面没有数，那么就是输出负一
        }
        s[++tt] = x; //插入元素入栈
    }
    return 0;
}
//单调栈实现找到一组数列找到左边第一个小于这个数的数，明白一点就是入栈的那个元素一定比栈顶元素要大，如果栈里面有元素的话，删除的元素都一定大于或者等于最后入栈的这个元素
//这就保证了栈里面的数一定是单调递增的，那样栈顶元素就是所有数里面最大的值，如果下一个数大于栈顶，那么栈顶就是第一个左边小于的数