/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        vector<int> dp(amount + 1, 0);
        dp[0] = 1; // 初始化

        for(int& coin : coins)
        {
            for(int j = coin; j <= amount; j++)
            {
                dp[j] = dp[j] + dp[j - coin];
            }
        }

        return dp[amount];
    }
};
// @lc code=end

