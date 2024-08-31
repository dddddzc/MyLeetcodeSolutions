/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowPtr = 0;
        for(int fastPtr = 0; fastPtr < nums.size(); ++fastPtr)
        {
            if(nums[fastPtr] != val)
            {
                nums[slowPtr] = nums[fastPtr];
                ++slowPtr;
            }
        }
        return slowPtr;
    }
};
// @lc code=end

