/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtracking(vector<int>& nums, int startIndex)
    {
        res.push_back(curr);
        if(startIndex == nums.size()) return;

        for(int i = startIndex; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            backtracking(nums, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

