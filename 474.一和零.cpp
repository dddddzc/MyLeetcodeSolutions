/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include<vector>
#include<string>
#include<utility>
using namespace std;

class Solution {
public:

    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[i][j]:容量为 i个0,j个1 的背包的最大子集长度
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 转移方程:
        // if(str[k] 选不了) dp[m][n] = dp[m][n];
        // if(str[k] 可选) dp[m][n] = max(dp[m][n], dp[m - str[k].zeors][j - str[k].ones] + 1)

        for(string& str : strs)
        {
            int zeros = 0; 
            int ones = 0;
            for(char& c : str)
            {
                if(c == '0') zeros++;
                else ones++;
            }

            for(int i = m; i >= zeros; i--)
            {
                for(int j = n; j >= ones; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

