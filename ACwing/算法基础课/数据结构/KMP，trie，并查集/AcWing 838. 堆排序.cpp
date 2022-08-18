#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int q[N];
int s = 0;
void down(int x)
{
    int t = x;
    if (x * 2 <= s && q[t] > q[x * 2])//如果存在左孩子，并且大于左孩子，那么t进行替换
    {
        t = x * 2;
    }
    //不能写成,因为这时的t是会变化的，我们要的是判断父节点是否有左右孩子
    /*
    if (t * 2 <= size && q[t] > q[t * 2])
    {
        t = t * 2;
    }
    */
    if (x * 2 + 1 <= s && q[t] > q[x * 2 + 1])//如果右孩子是最小的，那么记录右孩子
    {
        t = x * 2 + 1;
    }
    if (t != x)//如果孩子小于父节点，那么进行替换，与左右孩子中最小的那个进行替换
    {
        swap(q[x], q[t]);
        down(t);//然后继续递归
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    s = n;
    for (int i = n / 2; i >= 1; i--) //优化堆，使得空间复杂度由O(nlogn)到O(n)，这也是运用堆的性质，就是根节点小于左右孩子
    {
        down(i); //传入下标就好了，不需要说传入值
    }
    for (int i = 1; i <= m; i++)
    {
        cout << q[1] << " ";//先第一个输出
        q[1] = q[s];//把最后一个提上来
        s--;//size--
        down(1);//再把第一个进行判断，看是不是小于左右孩子
    }
    return 0;
}
//堆排序，时间复杂度为O(n)