#include <iostream>
using namespace std;
int n, m;
struct window
{
    int x1, x2, y1, y2;
    int id;
} ss[15];
int get(int x, int y)
{
    for (int i = n; i; i--)
    {
        if (x >= ss[i].x1 && x <= ss[i].x2 && y >= ss[i].y1 && ss[i].y2 >= y)//主要在这一部分进行判断
        {
            return i;
        }
    }
    return 0;
}
int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ss[i] = {x1, x2, y1, y2, i};
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int t = get(x, y);
        if (!t)
        {
            cout << "IGNORED" << endl;
        }
        else
        {
            cout << ss[t].id << endl;
            auto temp = ss[t];
            for (int i = t; i < n; i++)
            {
                ss[i] = ss[i + 1];
            }
            ss[n] = temp;
        }
    }
    return 0;
}