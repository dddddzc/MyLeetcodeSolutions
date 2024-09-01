/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 1) return 1;

        // 初始化:每个单字符串本身就是一个回文串
        int count = s.size();
        // dp[i][j]: [s[i],s[j]]子串是否是回文串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // 初始化dp数组
        for(int i = 0; i < s.size(); i++) dp[i][i] = true;
        for(int i = 1; i < s.size(); i++) dp[i][i - 1] = true; // 次对角线

        // 从下往上,倒数第二行开始
        for(int i = s.size() - 2; i >= 0; i--)
        {
            // 从右往左,倒数第一列开始
            for(int j = s.size() - 1; j > i; j--)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if(dp[i][j] == true) count++;
            }
        }

        return count;
    }
};
// @lc code=end

