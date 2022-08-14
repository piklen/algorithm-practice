#include <bits/stdc++.h>
using namespace std;
char ss[1000];
char s[20][20];
pair<int, int> a[110];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof a);
        int n, sslen;
        scanf("%s%d", ss + 1, &n);
        sslen = strlen(ss + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            int slen = strlen(s[i]);
            for (int j = 1; j + slen - 1 <= sslen; j++)
            {
                int flag = 1;
                for (int k = 0; k < slen; k++)
                {
                    if (ss[j + k] != s[i][k])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    if (j + slen - 1 > a[j].second)
                    {
                        a[j] = {i, j + slen - 1};
                    }
                }
            }
        }
        vector<pair<int, int>> ans;
        int pos = 1;
        int fflag = 1;
        while (pos <= sslen)
        {
            int id, l, r = 0;
            for (int i = 1; i <= pos; i++)
            {
                if (a[i].second > r)
                {
                    l = i;
                    r = a[i].second;
                    id = a[i].first;
                }
            }
            if (r >= pos)
            {
                ans.push_back({id, l});
                pos = r + 1;
            }
            else
            {
                cout << "-1" << endl;
                fflag = 0;
                break;
            }
        }
        if (fflag)
        {
            cout << ans.size() << endl;
            for (auto i : ans)
            {
                cout << i.first << " " << i.second << endl;
            }
        }
    }
    return 0;
}
