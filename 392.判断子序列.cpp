/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();

        // dp[i][j]:到s[i]和t[j]为止(不一定以他们为结尾),已经配对的字符个数
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
            }
        }

        if(dp[len1][len2] == len1) return true;

        return false;
    }
};
// @lc code=end

