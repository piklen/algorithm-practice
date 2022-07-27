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
bool cmp(struct stu a, struct stu b)
{
    if (a.score < b.score)
    {
        return true;
    }
    else if (a.score > b.score)
    {
        return false;
    }
    else if (a.na < b.na)
    {
        return true;
    }
    else if (a.na > b.na)
    {
        return false;
    }
    else if (a.age < b.age)
    {
        return true;
    }
    else
    {
        return false;
    }
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
        cout << a[i].na << " " << a[i].age << " " << a[i].score << endl;
    }
    return 0;
}
/*
1.学习sort多重排序在结构体类型中的应用，cmp中执行的顺序是从上到下的，因为用来if else if句型所以只进一个判断
2.sort对结构体排序是对整个排，排序的部分主要在cmp中
*/