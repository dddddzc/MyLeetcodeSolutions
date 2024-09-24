/*
 * @lc app=leetcode.cn id=2164 lang=cpp
 *
 * [2164] 对奇偶下标分别排序
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();

        // 奇数下标,非递增
        for(int i = 1; i < n; i += 2)
        {
            for(int j = i + 2; j < n; j += 2)
            {
                if(nums[j] > nums[i])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }

        // 偶数下标,非递减
        for(int i = 0; i < n; i += 2)
        {
            for(int j = i + 2; j < n; j += 2)
            {
                if(nums[j] < nums[i])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }

        return nums;
    }
};
// @lc code=end

