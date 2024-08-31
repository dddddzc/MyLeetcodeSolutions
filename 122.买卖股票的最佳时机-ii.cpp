/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int f0 = -prices[0];
        int f1 = 0;
        for(int& price : prices)
        {
            int temp = f0;
            f0 = max(f0, f1 - price);
            f1 = max(f1, price + temp);
        }

        return f1;
    }
};
// @lc code=end

