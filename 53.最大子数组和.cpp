/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int currMax = 0;
        for(int& x: nums)
        {
            // 记currMax为到当前为止的数组串中的结果
            currMax = max(currMax + x, x);
            res = max(res, currMax);
        }
        return res;
    }
};
// @lc code=end

