#include <iostream>
using namespace std;
int a[50], b[50], c[50];
int main()
{
    int n, m;
    cin >> n >> m;
    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = c[i - 1] * a[i];
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = (m % c[i] - cnt) / c[i - 1];
        cnt += c[i - 1] * b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}

//这个题目，感觉自己都没有确切的看懂题目，分析原因，第一点是因为题目太长，然后自己的内心产生了恐惧心理
//第二点自己的阅读能力不太行，关于这个题目解题的心得，首先不要慌张，沉下心来，慢慢想，第一题一般是按照题目给的逻辑顺序就能进行解答
//可以格外注意题目给的提示