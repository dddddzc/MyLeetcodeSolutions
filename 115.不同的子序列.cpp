/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        uint64_t tlen = t.size();
        uint64_t slen = s.size();

        vector<vector<uint64_t>> dp(tlen, vector<uint64_t>(slen, 0));

        if(t[0] == s[0]) dp[0][0] = 1;
        for(int i = 1; i < slen; i++)
        {
            if(t[0] == s[i]) dp[0][i] = dp[0][i - 1] + 1;
            else dp[0][i] = dp[0][i - 1];
        }

        for(int i = 1; i < tlen; i++)
        {
            for(int j = 1; j < slen; j++)
            {
                if(t[i] == s[j]) dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                else dp[i][j] = dp[i][j - 1];
            }
        }

        return dp[tlen - 1][slen - 1];


    }
};
// @lc code=end

