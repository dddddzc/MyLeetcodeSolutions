/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0; i < n - 2; i++)
        {
            // speed up
            // 三个最小值相加大于0
            if(nums[i] + nums[i + 1] + nums[i + 2] > 0)
            {
                return res;
            }
            // 三个最大值相加小于0
            if(nums[i] + nums[n - 2] + nums[n - 1] < 0)
            {
                continue;
            }
            
            // 对a去重
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if(nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left < right && nums[left + 1] == nums[left])
                    {
                        left++;
                    }
                    while(left < right && nums[right - 1] == nums[right])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

