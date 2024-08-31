/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0) return 0;

        // 现在dp[i][j]表示在第 * 天,至多进行i次交易的最大收益,j = 0未持有,j = 1持有.
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));

        // 初始化第一天
        for(int i = 0; i < k; i++) dp[i][1] = -prices[0];

        for(int& price : prices)
        {
            for(int i = 0; i <= k; i++)
            {
                int temp = dp[i][0];
                if(i >= 1) dp[i][0] = max(dp[i][0], dp[i - 1][1] + price);  // 卖出
                dp[i][1] = max(dp[i][1], temp - price);                 // 买入
            }
        }

        return dp[k][0];
    }
};
// @lc code=end

