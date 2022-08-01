//快速排序
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int q[N];
void quick_sort(int q[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int i = l - 1, j = r + 1, x = q[(l + r) / 2]; //因为在do{}while()结构中，do里面的一定会先执行，所以要先进行i与j的变化
    //x是基准元素，可以任意取，可以取第一个，可以取中间也可以random
    while (i < j)
    {
        do
        {
            i++;
        } while (q[i] < x); //使得左边的元素都小于基准元素
        do
        {
            j--;
        } while (q[j] > x); //使得右边的元素都大于基准元素
        if (i < j)
        {
            swap(q[i], q[j]); //双指针都停止时，则说明左边的元素大于基准元素，右边的元素小于基准元素，所以进行交换位置
        }
    }
    //分治，把他们都切成很小的段落，不断进行切分，不断进行上边的操作
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;
    return 0;
}