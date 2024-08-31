/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // f0 : 未持有 f1 : 持有
        // 转移方程:假设在卖出时支付手续费
        // f0 = max(f0, f1 + price - fee)
        // f1 = max(f1, f0 - price)
        int f0 = 0, f1 = - prices[0];

        for(int& price : prices)
        {
            f0 = max(f0, f1 + price - fee);
            f1 = max(f1, f0 - price);
        }

        return f0;
    }
};
// @lc code=end

