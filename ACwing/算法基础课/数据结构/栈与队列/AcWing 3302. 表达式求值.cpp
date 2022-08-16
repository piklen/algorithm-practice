#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <string>
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
        x = b - a; //因为a是栈顶，b是第二个栈顶，所以根据入栈先后顺序可以知道应该是b-a
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
    unordered_map<char, int> ff = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; //表达式符号进行分级
    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i++)
    {
        auto c = a[i];  //提取出这个字符来
        if (isdigit(c)) //判断是不是数字的字符，是则返回true不是则返回FALSE
        {
            int x = 0;
            int j = i;
            while (j < a.size() && isdigit(a[j]))
            {
                x = 10 * x + a[j] - '0'; //把这个数字的字符串给切出来
                j++;
            }
            i = j - 1;   //因为如果进了上一个判断，j就最少都会加1所以要减回来
            num.push(x); //把切出来的这个数放到num这个栈里面
        }
        else if (c == '(')
        {
            op.push(c); //如果是左括号就进行添加进符号的那一边
        }
        else if (c == ')') //如果是出现了右括号就需要进行计算括号内的东西
        {
            while (op.top() != '(') //当没有出现左括号时就一直进行计算
            {
                eval();
            }
            op.pop(); //删除左括号
        }
        else
        {
            while (op.size() && op.top() != '(' && ff[op.top()] >= ff[c]) //括号内优先级高的先进行运算
            {
                eval();
            }
            op.push(c); //把这个符号添加进行op这个栈里面
        }
    }
    while (op.size()) //如果还有符号能进行操作那么把剩余的给解决完，留下的应该都是同级的运算符
    {
        eval();
    }
    cout << num.top() << endl; //运算到最后num里面一定还剩一个
    return 0;
}
//使用stack进行构建树，然后进行中序遍历，进行求值