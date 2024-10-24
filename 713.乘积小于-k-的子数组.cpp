/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.size() == 0 || k <= 1) {
            return 0;
        }
        int ans = 0;
        int prod = 1;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod = prod * nums[right];

            while (prod >= k) {
                prod /= nums[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};
// @lc code=end

