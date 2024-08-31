/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 暴力 + sort
        // for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        // {
        //     *iter = (*iter) * (*iter);
        // }
        // std::sort(nums.begin(), nums.end());
        // return nums;

        // double ptr 
        vector<int> newArray(nums.size(), 0);
        int i = 0;
        int j = nums.size() - 1;
        int currIdx = j;
        for(i, j; i <= j; )
        {
            if(nums[i] * nums[i] < nums[j] * nums[j])
            {
                newArray[currIdx] = nums[j] * nums[j];
                --j;
                --currIdx;
            }
            else
            {
                newArray[currIdx] = nums[i] * nums[i];
                ++i;
                --currIdx;           
            }
        }
        return newArray;
    }
};
// @lc code=end

