#include <iostream>
#include <string>
using namespace std;
int l[30], r[30];
string v[30];
bool st[30];
void dfs(int i)
{
    cout << "(";
    //思考该怎么进行后序遍历的问题
    if (l[i] != -1 && r[i] != -1) //左右子树还存在，先进行左子树遍历
    {
        dfs(l[i]);
        //为什么写成dfs[r[i],编译器不报错？？？？？
        dfs(r[i]);
        cout << v[i];
    }
    else if (l[i] == -1 && r[i] == -1) //左右子树不存在，则进行输出
    {
        cout << v[i];
    }
    else //还有右子树，则进行输出后进行遍历右子树
    {
        cout << v[i];
        dfs(r[i]);
    }
    cout << ")";
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) //进行数据输入，然后进行父节点标记
    {
        cin >> v[i] >> l[i] >> r[i];
        if (l[i] != -1)
        {
            st[l[i]] = true; //表示有父节点，不为根节点
        }
        if (r[i] != -1)
        {
            st[r[i]] = true;
        }
    }
    //找到根节点
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            root = i;
            break;
        }
    }
    // cout<<root<<endl;
    //找到了根节点，然后选择dfs
    dfs(root);
    return 0;
}
//后缀表达式
/*
1.先知道中序后序先序遍历，先中后分别代表了中间哪个值（也就是父节点的遍历顺序）
2.遍历一般使用dfs，分三种情况，第一种是左右都还有子树，第二种是没有左子树了，只有右子树，则先进行输出，再进行遍历右子树
第三种是左右子树皆无，则直接进行输出
3.找到根节点的方法，根节点没有父节点，这是其特点
*/