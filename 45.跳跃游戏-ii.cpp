/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int end = 0;        // 记录每段的最后一个元素
        int cover = 0;      // 记录当前遍历过的元素cover范围,到了end的时候就更新(一段结束)
        int minStep = 0;    

        for(int i = 0; i < nums.size() - 1; i++)
        {
            cover = max(cover, i + nums[i]);
            if(cover >= nums.size() - 1) return minStep + 1;

            if(i == end)
            {
                end = cover;
                minStep++;
            }

        }
        return minStep;
    }
};
// @lc code=end

