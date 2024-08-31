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
        // if(nums.size() < 3)
        // {
        //     return {};
        // }

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 2; ++i)
        {
            // speed up
            if(nums[i] > 0)
            {
                return res;
            }

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

