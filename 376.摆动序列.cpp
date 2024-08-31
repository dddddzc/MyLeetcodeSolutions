/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 1;

        int res = 1;
        int currDiff;
        int lastDiff = 2;

        for(int i = 1; i < nums.size(); i++)
        {
            // 相等直接跳过
            if(nums[i] == nums[i - 1]) continue; 
            // 记录下当前的 diff 为正还是为负
            currDiff = (nums[i] - nums[i - 1]) > 0 ? 1 : -1;
            // 如果 currdiff != lastdiff, 则 res + 1
            // 如果相同,则说明当前的节点值可以取代之前的结点, res不变
            // 举例: 5 10 13 15 10 5
            // diff: 0  1  1  1 -1 -1
            // res:  1  2  2  2  3  3
            // 按此策略选的连续摆动序列:[5 15 10]
            // 拥有每个持续阶段的最后一个元素,和变动阶段的第一个元素
            if(currDiff != lastDiff) res++;
            // 更新当前的 diff
            lastDiff = currDiff;
        }
        return res;
    }
};
// @lc code=end

