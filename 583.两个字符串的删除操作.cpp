/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        // dp[i][j] : word1的前i个元素与word2的前j个元素的最长重复子序列长度
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return len1 + len2 - 2 * dp[len1][len2];
    }
};
// @lc code=end

