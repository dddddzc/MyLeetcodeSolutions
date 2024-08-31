/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currNum = nums[0];
        int slowPtr = 1;
        for(int fastPtr = 1; fastPtr < nums.size(); ++fastPtr)
        {
            if(nums[fastPtr] > currNum)
            {
                nums[slowPtr] = nums[fastPtr];
                ++slowPtr;
                currNum = nums[fastPtr];
            }
        }
        return slowPtr;
    }
};
// @lc code=end

