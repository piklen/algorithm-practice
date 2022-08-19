#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int si, h[N], ph[N], hp[N], m;//hp表示head——>point
void heap_swap(int x, int y)//交换操作
{
    swap(ph[hp[x]], ph[hp[y]]);//ph[]与hp[]互为映射关系，用来标记这是第几个插入的数
    //交换外部指针
    swap(hp[x], hp[y]);//交换第几个k的指针
    swap(h[x], h[y]);//交换值
}
void down(int x)
{
    int t = x;
    if (x * 2 <= si && h[t] > h[x * 2])
    {
        t = x * 2;
    }
    if (x * 2 + 1 <= si && h[t] > h[x * 2 + 1])
    {
        t = x * 2 = 1;
    }
    if (t != x)
    {
        heap_swap(t, x);
        down(t);
    }
}
void up(int x)
{
    while (x / 2 && h[x] < h[x / 2])//up操作，当出现子节点小于父节点时，向上进行交换
    {
        heap_swap(x, x / 2);
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int a, b;
        if (s == "I")//插入
        {
            cin >> a;
            si++;//堆容量添加
            m++;//第几个插入
            ph[m] = si;//第m个插入的位置是size
            hp[si] = m;//第size个点的映射坐标是m
            h[si] = a;
            up(si);//因为插入在最后所以进行up操作
        }
        else if (s == "PM")//查询最小的元素
        {
            cout << h[1] << endl;
        }
        else if (s == "DM")//删除最小的元素
        {
            heap_swap(1, si);//先进行交换
            si--;//删除最后一个
            down(1);//把第一个元素找到合适的位置
        }
        else if (s == "D")//删除第k个数
        {
            cin >> a;
            a = ph[a]; //?//ph[]里面存的是第k个数存的坐标
            heap_swap(a, si);//换到最后去
            si--;//容量减小
            down(a);
            up(a);//down或者up只能执行一步
        }
        else//把第k个数替换出来
        {
            cin >> a >> b;
            a = ph[a];//先找到第k个数
            h[a] = b;//然后值进行替换
            down(a);
            up(a);//找到合适的位置
        }
    }
    return 0;
}
//堆的五种基本操作