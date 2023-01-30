class Solution
{
public:
    string s[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string res;
    // void dfs(int i)
    // {
    //     if(i>=digits.size())
    //     {
    //         return ;
    //     }
    //     else
    //     {
    //         int index=digits[i]-'0';
    //         for(int j=0;j<s[i].size();j++)
    //         {
    //             res+=s[i][j];
    //             dfs(i+1);
    //         }
    //     }
    // }
    vector<string> letterCombinations(string digits)
    {
        void dfs(int i)
        {
            if (i >= digits.size())
            {
                return;
            }
            else
            {
                int index = digits[i] - '0';
                for (int j = 0; j < s[i].size(); j++)
                {
                    res += s[i][j];
                    dfs(i + 1);
                }
            }
        }
        dfs(0);
        return res;
    }
};