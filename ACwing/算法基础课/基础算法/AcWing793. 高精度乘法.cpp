#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> mul(vector<int> &A, int b) //高精度x低精度
{
    vector<int> C;
    int t = 0;                              //t存储的是b乘以A中一位的值
    for (int i = 0; i < A.size() || t; i++) //包含了乘法与进位，进位在t哪
    {
        if (i < A.size()) //乘法部分
        {
            t += A[i] * b; //把b当做一个整数来乘，感觉范围在1e8，如果开long long 会更大
        }
        C.push_back(t % 10); //取末尾进行存储，因为可以证明它就是在这一阶段最小的值
        t /= 10;             //进位
    }
    //其实哪个t也可以写成如下：
    // while(t)
    // {
    //     C.push_back(t%10);
    //     t/=10;
    // }
    while (C.size() > 1 && C.back() == 0) //老套路，去除前导0
    {
        C.pop_back();
    }
    return C;
}
int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }
    auto C = mul(A, b);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    return 0;
}
//高精度乘以高精度
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> mul(vector<int> &A, vector<int> &B)
{
    vector<int> C(A.size() + B.size() + 10, 0); //开辟这么大空间并且初始化为0，可以证明AxB最大长度小于A+B的长度
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            C[i + j] += A[i] * B[j]; //内外两层循环，起效果就是模拟我们正常进行乘法运算，C[i+j]用来存乘积，起下标就是模拟乘法的位置
        }
    }
    int t = 0;
    for (int i = 0; i < C.size(); i++) //将C[i+j]的值进行转存到C[i],因为C[i+j]里面的值一开始并不是一个数字，是很多数值的累加
    {
        t += C[i];
        C[i] = t % 10;
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back(); //前导0
    return C;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }
    auto C = mul(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    return 0;
}
//高精度乘以高精度