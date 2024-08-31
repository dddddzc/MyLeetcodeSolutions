/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] 到下标为i的房间为止的最高金额
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int j = 2; j < nums.size(); j++) // 遍历容量
        {
            dp[j] = max(dp[j - 2] + nums[j], dp[j - 1]);
        }

        return dp[nums.size() - 1];
    }
};
// @lc code=end

