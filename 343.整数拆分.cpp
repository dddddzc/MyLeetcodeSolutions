/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        // dp[i] 即数 i 能拆出来的最大乘积
        vector<int> dp(n + 1, 0);
        dp[2] = 1;

        // dp[4] : 1 * dp[3], 2 * dp[2], 3 * dp[1]
        //         1 * 3    , 2 * 2    , 3 * 1
        for(int i = 3; i <= n; i++) // 该层循环求 dp[i]
        {
            for(int j = 1; j <= min(i / 2, 3); j++) // 该层循环求 dp[i] 的各种可能情况 j * dp[i - j]
            {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }

        return dp[n];
    }
};
// @lc code=end

