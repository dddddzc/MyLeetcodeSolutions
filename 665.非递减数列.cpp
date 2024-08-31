/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2)
        {
            return true;
        }

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i - 1])
            {
                int temp = nums[i];
                nums[i] = nums[i - 1];
                if( is_sorted(nums.begin(), nums.end()) )
                {
                    return true;
                }
                else
                {
                    nums[i - 1] = temp;
                    nums[i] = temp;
                    return is_sorted(nums.begin(), nums.end());
                }

            }
        }

        return true;
    }
};
// @lc code=end

