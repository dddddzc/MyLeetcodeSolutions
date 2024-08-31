/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 设正的一堆为 x, 则负的一堆为 -(sum - x),加和为x - (sum - x) = 2x - sum
        // 即求 2x = sum + target,即求有多少种选出 x = (sum + target) / 2的方法。
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum) return 0;
        if( (sum + target) % 2 == 1) return 0;
        int x = (sum + target) / 2;

        // // 设 dp[j] 为能让结果为 j 的方法数目
        vector<int> dp(x + 1, 0);
        dp[0] = 1; // 一个都不选
        
        // 转移方程:dp[j] += dp[j - nums[i]]
        for(int& num : nums)
        {
            for(int j = x; j >= num; j--)
            {
                dp[j] = dp[j] + dp[j - num];
            }
        }
        return dp[x];
    }
};
// @lc code=end

