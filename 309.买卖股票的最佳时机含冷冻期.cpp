/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        int pre = 0, f0 = 0, f1 = -prices[0];
        for(int& price : prices)
        {
            int temp_f0 = f0;
            f0 = max(f0, f1 + price);
            f1 = max(f1, pre - price);
            pre = temp_f0; // pre需要记录更新前的f0
        }
        return f0;
    }
};
// @lc code=end

