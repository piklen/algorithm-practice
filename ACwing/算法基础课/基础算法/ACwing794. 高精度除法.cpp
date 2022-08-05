#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
//高精度除以低精度，把高精度分开，再用r = r * 10 + B[i];的形式存储数值
vector<int> div(vector<int> &B, int &b, int &r)
{
    vector<int> C;
    for (int i = 0; i < B.size(); i++)
    {
        r = r * 10 + B[i];  //r中存储数值，并且余数也在这
        C.push_back(r / b); //整除
        r %= b;             //余数留下，用来下一位除
    }
    reverse(C.begin(), C.end()); //因为这一次的前导0出现在前面
    while (C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    return C;
}
int main()
{
    string A;
    int b, r = 0;
    cin >> A >> b;
    vector<int> B;
    for (int i = 0; i < A.size(); i++)
    {
        B.push_back(A[i] - '0');
    }
    auto C = div(B, b, r);
    for (int i = C.size() - 1; i >= 0; i--) //除法的运算逻辑是从前向后的
    {
        cout << C[i];
    }
    cout << endl
         << r << endl;
    return 0;
}