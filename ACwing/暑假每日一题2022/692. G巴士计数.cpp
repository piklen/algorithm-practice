#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5010;
int ans[N];
int ss[N];
int main()
{
    int t;
    cin >> t;
    for (int aa = 1; aa <= t; aa++)
    {
        int n;
        memset(ans, 0, sizeof(ans));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            for (int j = a; j <= b; j++)
            {
                ans[j]++;
            }
        }
        int k;
        cin >> k;
        memset(ss, 0, sizeof(ss));
        for (int i = 0; i < k; i++)
        {
            int cnt;
            cin >> cnt;
            ss[i] = ans[cnt];
        }
        cout << "Case #" << aa << ": ";
        for (int i = 0; i < k; i++)
        {
            cout << ss[i];
            if (i != k - 1)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
        }
        // system("pause");
    }
    return 0;
}
//简单的模拟题，也可以进行优化，开两个数组，一个用来存起点，一个用来存末结点，如果输入的x在这中间ans++