class Solution
{
public:
    int myAtoi(string s)
    {
        s = " " + s;
        long long ans = 0;
        string res;
        int flag = 1;
        int f = 0;
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' && f == 0)
            {
                continue;
            }
            if (s[i] == '+' || s[i] == '-')
            {
                if (s[i - 1] != ' ')
                {
                    break;
                }
                if ('0' <= s[i + 1] && s[i + 1] <= '9')
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (f == 1)
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    res += s[i];
                }
                else
                {
                    break;
                }
            }
            if (s[i] >= '0' && s[i] <= '9' && f == 0)
            {
                res += s[i];
                f = 1;
                if (s[i - 1] == '-')
                {
                    flag = -1;
                }
            }
            if (f == 0)
            {
                return 0;
            }
        }
        f = 0;
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] != '0')
            {
                f = 1;
            }
            if (f == 1)
            {
                ans = ans * 10 + res[i] - '0';
                if (ans > INT_MAX)
                {
                    if (flag == 1)
                    {
                        return INT_MAX;
                    }
                    else
                    {
                        return INT_MIN;
                    }
                }
            }
        }
        return ans * flag;
    }
};