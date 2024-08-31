/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4)
        {
            return {};
        }

        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for(int j = i + 1; j < n - 2; ++j)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;
                while(left < right)
                {
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target)
                    {
                        left++;
                    }
                    else if(sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while(left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

