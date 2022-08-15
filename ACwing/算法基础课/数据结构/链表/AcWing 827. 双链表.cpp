#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int l[N], e[N], r[N], idx;
void init() //双链表初始化，
{
    l[1] = 0; //设立两个点，最左端的为0，最右端的为1
    r[0] = 1;
    idx = 2; //标记步数为2；
}
void add(int k, int x) //在第k个数的右边添加x
{
    e[idx] = x;    //先进行数据储存
    r[idx] = r[k]; //这个数的右指针指向k的右指针指向的数
    l[idx] = k;    //左指针指向k
    l[r[k]] = idx; // k右指针指向的那个数的左指针指向加入的这个数的坐标
    r[k] = idx;    // k的右指针指向加入的这个数，这一步和上一步不能反
    idx++;         //步数加一
}
void remove(int k) //移除k这个数，相当于移除第k-1个数
{
    r[l[k]] = r[k]; //这个数的左指针指向这个数的右指针
    l[r[k]] = l[k]; //这个数的右指针指向这个数的左指针
}
int main()
{
    int t;
    cin >> t;
    init();
    while (t--)
    {
        string a;
        cin >> a;
        int k, x;
        if (a == "R") //删除最右边的数
        {
            cin >> x;
            add(l[1], x); // 1是双向链表最右边的数，所以1的左指针指向的数就是最右边插入的数
        }
        else if (a == "L") //删除最左边的数
        {
            cin >> x;
            add(0, x); //不能写成add(r[0],x)因为r[0]此时已经指向了一个数，并不是最左端的数，而是左端倒数第2个数
            //所以要写成add(0,x);
        }
        else if (a == "D") //删除第k个插入的数
        {
            cin >> k;
            remove(k + 1); //因为初始化时从0开始的，所以remove里面删除的是第k-1个数
            //因为初始化加了两个节点，而且从0开始，所以第k个数的下标为k + 2 - 1
        }
        else if (a == "IL")//在第k个数的左边添加一个数
        {
            cin >> k >> x;
            add(l[k + 1], x); //不能写成在第add(k,x);
        }
        else
        {
            cin >> k >> x;//在第k个数右边添加一个数
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])//从最左端一直输出到最右端，r[0]表示最左端，1始终在最右端
    {
        cout << e[i] << " ";
    }
    return 0;
}