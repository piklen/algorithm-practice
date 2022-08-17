#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int son[N][26], cnt[N];
string s;
int idx = 0;
void insert(string ss)
{
    int q = 0;                          //是根节点，也是空结点
    for (int i = 0; i < ss.size(); i++) //遍历这个字符串
    {
        int u = s[i] - 'a'; //将其字符映射到0~25
        if (!son[q][u])     //如果这个结点不存在
        {
            son[q][u] = ++idx;
            构造这个结点
        }
        q = son[q][u]; //将这个结点的位置进行存储，实质上是进行了树的构建
    }
    cnt[q]++; //将最后一个尾结点进行标记，这样就能够知道这样的字符串数量有多少了
}
void query(string ss)
{
    int q = 0;
    for (int i = 0; i < ss.size(); i++)
    {
        int u = s[i] - 'a';
        if (!son[q][u]) //如果不存在这样一个结点，说明没有这个字符串
        {
            cout << "0" << endl; //输出0，并且返回上一程序
            return;
        }
        q = son[q][u]; //能到这一步肯定是存在这样一个字符串的，输出以这个字符结尾的字符串的数量，可能为0也可能为其他数
    }
    cout << cnt[q] << endl;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        if (a == "I") //插入操作
        {
            cin >> s;
            insert(s);
        }
        else //查询操作
        {
            cin >> s;
            query(s);
        }
    }
    return 0;
}
// trie树，就是把字符串串构建成树，并且用idx做步数标记，也就是唯一值，来进行统计字符串