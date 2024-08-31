/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int maxLen = 0;
        // dp[i][j]:以下标i - 1结尾的nums1子数组,与以下标j - 1结尾的nums2子数组,最长重复子数组长度为dp[i][j]
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0)); // dims : len1 * len2

        // 转移方程:
        // if(nums1[i] == nums2[j]) dp[i][j] = dp[i - 1][j - 1] + 1

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if(dp[i][j] > maxLen) maxLen = dp[i][j];
            }
        }

        return maxLen;
    }
};
// @lc code=end

