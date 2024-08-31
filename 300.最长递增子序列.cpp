/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] : 从任意位置开始，以nums[i] 作为结尾的最长递增子序列长度。
        int maxLen = 1;
        vector<int> dp(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] > maxLen) maxLen = dp[i];
        }

        return maxLen;
    }
};
// @lc code=end

