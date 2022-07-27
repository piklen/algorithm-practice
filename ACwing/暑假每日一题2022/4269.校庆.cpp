#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string c, d; // c表示校友中年纪最大的人，d表示来宾中年纪最大的人
int ans = 0;
string max(string a, string b)
{
    int A = 0, B = 0;
    for (int i = 6; i <= 13; i++)
    {
        A = A * 10 + a[i] - '0';
        B = B * 10 + b[i] - '0';
    }
    if (A < B)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    int n, m;
    cin >> n;
    unordered_map<string, bool> hs;
    while (n--)
    {
        string str;
        cin >> str;
        hs[str] = true;
    }
    cin >> m;
    while (m--)
    {
        string str;
        cin >> str;
        if (hs[str]) //如果在来宾中找到了校友
        {
            ans++;
            if (c.size()) //也就是已经有了校友
            {
                c = max(str, c);
            }
            else
            {
                c = str;
            }
        }
        else //查找来宾中年龄最大的
        {
            if (d.size()) //也就是已经有了来宾
            {
                d = max(str, d);
            }
            else
            {
                d = str;
            }
        }
    }
    if (ans)
    {
        cout << ans << endl
             << c << endl;
    }
    else
    {
        cout << "0" << endl
             << d << endl;
    }
    return 0;
}

//这个题的主要思路是学会使用unordered_map这个hash函数，提高查找效率
// 哈希表
// 题目给出的意思是一开始给出n个身份证号，这些身份证号都是 校友的身份证号，所以我们要存储这些身份证号
//             然后再给出m行表示 参加这次校庆的人的身份证号
//                 我们要从m行中找到是否有校友参加， 如果有找到最大年龄的校友

//                     既然要找校友身份证，那么我们就需要高效的存储和查找，而哈希表正好满足这个要求，哈希表的插入和查找都是O(1)

//                         而身份证有18位，而已还带字母X，所以我们可以用字符串数组存储，这里为了方便可以直接用string类存储
//         找到参加的人是校友后我们还要找到年龄最大的校友，我们可以再遍历参加的人的同时，用一个新的string类存储当前最大年龄的校友

//         由于身份证号7
//         - 14位是出生年月，一共有8位数字，也就是说小于10 ^
//     9，所以我们可以把他们的出生年月用一个int来存放 然后把当前遍历到的校友和当前年龄最大的校友比较，然后再更新最大年龄的校友，并更新所有校友的人数
//     要注意的是，题目还存在没有校友参加的情况，所以我们还要用同样的方法在不是校友的人中找到年龄最大的人
//时间复杂度 O（n）