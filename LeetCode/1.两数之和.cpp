/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] > target)
            {
                r--;
            }
            else if (nums[l] + nums[r] < target)
            {
                l++;
            }
            else
            {
                ans = {l, r};
                break;
            }
        }
        return ans;
    }
};
// @lc code=end
