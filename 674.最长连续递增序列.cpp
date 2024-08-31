/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // dp[i] : 以nums[i] 作为结尾的最长递增子序列长度。
        int pre = 1, curr = 1, maxLen = 1;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1]) 
            {
                curr = max(curr, pre + 1);
                pre = curr;
            }
            else
            {
                pre = 1;
                curr = 1;
            }
            
            if(curr > maxLen) maxLen = curr;
        }

        return maxLen;
    }
};
// @lc code=end

