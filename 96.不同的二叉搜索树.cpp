/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if(n <= 2) return n;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++)
        {
            for(int j = 1; j <= i; j++) // 以j为头结点的树的个数
            {
                // dp[j - 1]:小于j的数组成的左子树的个数
                // dp[i - j]: 大于j的数组成的右子树的个数
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end

