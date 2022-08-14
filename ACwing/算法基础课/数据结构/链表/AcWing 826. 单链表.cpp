#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], idx, head;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点
//链表初始化
void init()
{
    head = -1; //初始化时head表示它指向的点是空
    idx = 0;   // idx来表示步数计算的指针
}
//在头结点后添加一个元素
void add_to_head(int x) //在head与-1之间插入x这个值
{
    e[idx] = x;
    ne[idx] = head; //插入的那个元素的指针指向head指向的值就是-1
    head = idx;     //把head指向当前步数的指针
    idx++;          //步数++
}
//在第k个元素后添加一个元素
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k]; //把插入这个值的指针指向k指向的那个指针
    ne[k] = idx;     // k的指针指向插入的这个下标
    idx++;
}
//删除第k+1个结点后面的数
void remove(int k)
{
    ne[k] = ne[ne[k]]; //删除第k+1个点，就是把k的指针指向k指针指向的指针的下一个
}
int main()
{
    int m;
    cin >> m;
    init();
    while (m--)
    {
        char c;
        cin >> c;
        if (c == 'H')
        {
            int x;
            cin >> x;
            add_to_head(x); //把x插入到头指针
        }
        else if (c == 'D')
        {
            int x;
            cin >> x;
            if (!x)
            {
                head = ne[head]; //如果x是0那么就把头指针删除，也就是把head指向ne[head]，其实head是空的
            }
            else
            {
                remove(x - 1); //删除第k个插入的数
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            add(x - 1, y); //添加到第k个数
        }
    }
    for (int i = head; i != -1; i = ne[i]) // head开始时是空的，但是插入第一个时就有值了
    {
        cout << e[i] << " ";
    }
    return 0;
}