#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
    //先进行开辟空间
    int n, total;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        memset(a[i], 0, n * sizeof(int));
    }
    //进行数组输出
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    //进行数据处理及读入
    a[0][0] = total = 1;
    int x = 0, y = 0;
    while (total < n * n)
    {
        //向右
        while (x + 1 < n && !a[y][x + 1])
        {
            a[y][++x] = ++total;
        }
        //向下
        while (y + 1 < n && !a[y + 1][x])
        {
            a[++y][x] = ++total;
        }
        //向左
        while (x - 1 >= 0 && !a[y][x - 1]) //进行边框限制
        {
            a[y][--x] = ++total;
        }
        //向上
        while (y - 1 >= 0 && !a[y - 1][x])
        {
            a[--y][x] = ++total;
        }
    }
    //进行输出
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
    //进行清空内存
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
/*
1.学习如何开辟动态2维数组，以及清理内存
2.贪吃蛇这个也告诉了我可以用循环做很多的事，只要条件足够
*/