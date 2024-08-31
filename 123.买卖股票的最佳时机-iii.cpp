/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;

        // 现在dp[i][j]表示在第 * 天,至多进行i次交易的最大收益,j = 0未持有,j = 1持有.
        vector<vector<int>> dp(3, vector<int>(2, 0));

        // 初始化第一天
        dp[0][1] = -prices[0];
        dp[1][1] = -prices[0];
        dp[2][1] = -prices[0];

        for(int& price : prices)
        {
            for(int i = 0; i <= 2; i++)
            {
                int temp = dp[i][0];
                if(i >= 1) dp[i][0] = max(dp[i][0], dp[i - 1][1] + price);  // 卖出
                dp[i][1] = max(dp[i][1], temp - price);                 // 买入
            }
        }

        return dp[2][0];
    }
};
// @lc code=end

