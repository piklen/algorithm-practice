#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <stack>
using namespace std;
stack<int> num;
stack<char> op;
void eval()
{
    int x;
    auto a = num.top();
    num.pop();
    auto b = num.top();
    num.pop();
    auto c = op.top();
    op.pop();
    if (c == '+')
    {
        x = a + b;
    }
    else if (c == '-')
    {
        x = b - a;
    }
    else if (c == '*')
    {
        x = a * b;
    }
    else
    {
        x = b / a;
    }
    num.push(x);
}
int main()
{
    unordered_map<char, int> ff = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        auto c = a[i];
        if (isdigit(c))
        {
            int x = 0;
            int j = i;
            while (j < a.size() && isdigit(a[j]))
            {
                x = 10 * x + a[j] - '0';
                j++;
            }
            i = j - 1;
            num.push(x);
        }
        else if (c == '(')
        {
            op.push(c);
        }
        else if (c == ')')
        {
            while (op.top() != '(')
            {
                eval();
            }
            op.pop();
        }
        else
        {
            while (op.size() && op.top() != '(' && ff[op.top()] >= ff[c])
            {
                eval();
            }
            op.push(c);
        }
    }
    while (op.size())
    {
        eval();
    }
    cout << num.top() << endl;
    return 0;
}