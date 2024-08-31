/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        // 如果 n = 1,那么只有一种
        // 如果 n = 2,那么有两种 1 + 1 / 2
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end

