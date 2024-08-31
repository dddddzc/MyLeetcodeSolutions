/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) // 求组合,但是可以多次选
    {
        // dp[j] : 表示 j 最少需要 dp[j] 个完全平方数
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= int(sqrt(n)) + 1; i++) // 遍历数字
        {  
            for(int j = i * i; j <= n; j++)            // 遍历背包容量
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }

        return dp[n];
    }

};

// @lc code=end

