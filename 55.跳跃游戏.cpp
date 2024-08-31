/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty() || nums.size() == 1) return true;
        int maxIndexReach = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            // 加上 if 是为了防止[0, 2, 3]这种情况
            if(i <= maxIndexReach) maxIndexReach = max(i + nums[i],  maxIndexReach);
            if(maxIndexReach >= (nums.size() - 1)) return true;
        }
        return false;
    }
};
// @lc code=end

