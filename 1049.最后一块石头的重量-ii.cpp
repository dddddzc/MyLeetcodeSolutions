/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;

        // dp[j] 表示容量为 j 的背包能表示的最大值
        // 如果dp[target] = target,则结果为 target - target = 0
        // 否则设dp[target] = m != 0, 则另一堆为 sum - m, 结果为 (sum - m) - m = sum - 2m 
        vector<int> dp(target + 1);

        for(int i = 0; i < stones.size(); i++)
        {
            for(int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[target];
    }
};
// @lc code=end

