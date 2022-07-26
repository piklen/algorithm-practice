#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct stu
{
    string na;
    int age;
    int score;
};
bool cmp(struct stu c, struct stu d)
{
    return c.score < d.score;
}
struct stu a[1010];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].na >> a[i].age >> a[i].score;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (a[i].score == a[i + 1].score)
        {
            if (a[i].na < a[i + 1].na)
            {
                cout << a[i].na << " " << a[i].age << " " << a[i].score << endl;
            }
            else if (a[i].na > a[i + 1].na)
            {
                cout << a[i + 1].na << " " << a[i + 1].age << " " << a[i + 1].score << endl;
            }
            else
            {
                if (a[i].age < a[i + 1].age)
                {
                    cout << a[i].na << " " << a[i].age << " " << a[i].score << endl;
                }
                else
                {
                    cout << a[i + 1].na << " " << a[i + 1].age << " " << a[i + 1].score << endl;
                }
            }
        }
        else
        {
            cout << a[i].na << " " << a[i].age << " " << a[i].score << endl;
        }
    }
    return 0;
}
