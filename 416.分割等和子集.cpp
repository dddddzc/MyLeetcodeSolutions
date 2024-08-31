/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include <numeric> 
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // nums的总和需要是偶数.
        int S = accumulate(nums.begin(), nums.end(), 0);
        if(S % 2 == 1) return false;
        int target = S / 2;
        int n = nums.size();

        // dp[j] 表示: 在第 0-i 个数字中任选,能否使得和为j.
        vector<int> dp(target + 1, 0);
        if(nums[0] <= target) dp[nums[0]] = 1;

        for(int i = 1; i < n; i++)
        {
            int num = nums[i];
            for(int j = target; j >= num; j--)
            {
                dp[j] = dp[j] | dp[j - num];
            }
        }

        return dp[target];
    }
};
// @lc code=end

