/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10002); // 10002为某个较大的数,便于后续取min
        dp[0] = 0; // 初始化

        for(int& coin : coins)
        {
            for(int j = coin; j <= amount; j++)
            {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }

        if(dp[amount] == 10002) return -1;
        return dp[amount];
    }
};
// @lc code=end

