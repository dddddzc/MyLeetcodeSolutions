/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowPtr = 0;
        for(int fastPtr = 0; fastPtr < nums.size(); ++fastPtr)
        {
            if(nums[fastPtr] != 0)
            {
                nums[slowPtr] = nums[fastPtr];
                ++slowPtr;
            }
        }
        for(int i = slowPtr; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};
// @lc code=end

