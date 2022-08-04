#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size()) //因为要进行默认A>=B所以直接返回这个判断结果就好了
    {
        return A.size() > B.size();
    }

    for (int i = A.size(); i >= 0; i--)
    {
        if (A[i] != B[i])
        {
            return A[i] > B[i]; //这里也是同理，返回值为A>=B
        }
    }
    return true; //两个值相等也返回TRUE
}

vector<int> sub(vector<int> &A, vector<int> &B) //同高精度加法的取地址
{
    vector<int> C;
    int t = 0;                         //用来借位
    for (int i = 0; i < A.size(); i++) //因为默认A>=B所以他的长度也是大于或等于B
    {
        t = A[i] - t; //如果需要借位就先减去
        if (i < B.size())
        {
            t -= B[i]; //当B还没有减完就继续减
        }
        C.push_back((t + 10) % 10); //如果t为负数这样同样可以使得获取出这个数
        if (t < 0)                  //如果t小于0那么就进行借位
        {
            t = 1;
        }
        else
        {
            t = 0; //不然就赋值为0表示这个个位的处理完了
        }
    }

    while (C.size() > 1 && C.back() == 0) //去掉前导0，但是要留一个
    {
        C.pop_back();
    }

    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0'); //逆序存储
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }

    if (cmp(A, B)) //如果A>=B那么A当被减数，B当减数
    {
        auto C = sub(A, B); //C11标准，自动获取数据类型
        for (int i = C.size() - 1; i >= 0; i--)
        {
            cout << C[i]; //逆序输出
        }
        return 0;
    }
    else
    {
        auto C = sub(B, A); //如果A<B那么相当于B是被减数，A是减数，前面加-就可以了
        cout << "-";
        for (int i = C.size() - 1; i >= 0; i--)
        {
            cout << C[i];
        }
        return 0;
    }
}
//高精度减法关键是在借位与判断大小，以及处理负数