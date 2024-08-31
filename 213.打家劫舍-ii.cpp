/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int rob_easy(vector<int>& nums, int start, int end) {
        int len = end - start;
        if(len == 0) return 0;
        if(len == 1) return nums[start];

        vector<int> dp(len, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for(int j = 2; j < len; j++) // 遍历容量
        {
            dp[j] = max(dp[j - 2] + nums[j + start], dp[j - 1]);
        }

        return dp[len - 1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        // rob_zero : 偷第0个,不能偷第1个和最后一个
        // rob_no_zero : 不偷第一个,后边的都可以偷
        // [start, end) : 有 end - start 个元素
        int rob_zero = nums[0] + rob_easy(nums, 2, nums.size() - 1);
        int rob_no_zero = rob_easy(nums, 1, nums.size());

        return max(rob_zero, rob_no_zero);
    }
};
// @lc code=end

