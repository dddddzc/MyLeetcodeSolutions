/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false); // 用vector<int>代替vector<bool>
        dp[0] = true;

        for(int i = 1; i <= s.size(); i++) // 排列问题,先遍历背包容量
        {
            for(int j = 0; j < wordDict.size(); j++) // 遍历字典(物品)
            {
                string currStr = wordDict[j];
                if(currStr.size() > i) continue;
                string subs = s.substr(i - currStr.size(), currStr.size());

                if(dp[i - currStr.size()] == true && currStr == subs)
                {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

