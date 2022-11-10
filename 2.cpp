#include <iostream>
using namespace std;
struct jz
{
    int a;
    int b;
} arr[1010];
int main()
{
    int n;
    cin >> n;
    int brr[n][101];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].a; //进制
        cin >> arr[i].b; //十进制数
    }
    int i = 0;
    while (n > 0)
    {
        n--;
        int j = 0;
        while (arr[i].b >= arr[i].a)
        {
            brr[i][j] = arr[i].b % arr[i].a;
            arr[i].b = arr[i].b / arr[i].a;
            j++;
        }
        if (arr[i].b != 0)
        {
            j++;
            brr[i][j] = arr[i].b;
        }
        for (int i1 = 0; i1 < n; i1++)
        {
            for (int j1 = j; j1 >= 0; j--)
            {
                if (brr[i1][j1] > 9)
                {
                    printf("%c", brr[i1][j1] - 10 + 65);
                }
                else
                    cout << brr[i1][j1];
            }
            cout << endl;
        }
        i++;
    }
    return 0;
}
