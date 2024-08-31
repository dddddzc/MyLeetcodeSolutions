/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }

        int sum = 0;
        int subArrayLen = INT_MAX;
        for(int i = 0, j = 0; j < nums.size(); ++j)
        {
            sum += nums[j];
            while(sum >= target)
            {
                subArrayLen = min(subArrayLen, j - i + 1);
                sum = sum - nums[i];
                i++;
            }
        }
        return subArrayLen == INT_MAX ? 0 : subArrayLen;
    }
};

// @lc code=end

