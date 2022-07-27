#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool first = true;
char g[26][7][6];
string word;
void put(string s)
{
    if (s.empty()) //如果进来的是空的则返回
    {
        return;
    }
    if (first) //如果是第一行，则不进行转行
    {
        first = false;
    }
    else
    {
        cout << endl; //进行转行
    }
    char str[7][60] = {0};             // 6*10-1最多59所以开60是够的
    for (int i = 0; i < s.size(); i++) //拆开单词里面的每一个字母
    {
        for (int j = 0; j < 7; j++) //有7行
        {
            for (int k = 0; k < 5; k++) //每行5个字符
            {
                str[j][i * 6 + k] = g[s[i] - 'A'][j][k]; //核心str里面存的是列的计算，每个字母占五个字符列加一个空格列
                // s[i]-'A'表示找到这一个字符
            }
        }
    }
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j < 7; j++)
        {
            str[j][i * 6 - 1] = ' '; //行末加空格
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout << str[i] << endl; //进行输出
    }
}
int main()
{
    //进行输入
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            cin >> g[i][j]; //进行26个字符的读取
        }
    }

    char c;
    while ((c = getchar()) != -1) //-1表示回车，这表示空格也能进行读入
    {
        if (c >= 'A' && c <= 'Z')
        {
            word += c; //有效字符读入
        }
        else
        {
            put(word); //分段进行输出，也就是输出一个单词
            word = "";
        }
    }

    return 0;
}
//这个主要的体现思想在分开每一个字母，然后用数组去存储，存储的过程中它有坐标变换