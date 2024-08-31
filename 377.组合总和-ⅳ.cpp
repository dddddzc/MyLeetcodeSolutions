/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start

#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for(int i = 0; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i >= nums[j] && dp[i] < __INT_MAX__ - dp[i - nums[j]]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
// @lc code=end

