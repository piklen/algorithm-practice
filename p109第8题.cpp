class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int minn = 200000, id;
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i]) < minn)
            {
                minn = abs(nums[i])
                {
                    id = i;
                }
            }
        } //找到最小值的位置
        int l = id;
        int r = id + 1;
        vector<int> q;
        while (l >= 0 && r < nums.size())
        {
            if (nums[l] * nums[l] < (num[r] * nums[r]))
            {
                q.push_back(nums[l] * nums[l]);
                l--;
            }
            else
            {
                q.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        while (l >= 0)
        {
            q.push_back(nums[l] * nums[l]);
            l--;
        }
        while (r < nums.size())
        {
            q.push_back(nums[r] * nums[r]);
            r++;
        }
        return q;
    }
};