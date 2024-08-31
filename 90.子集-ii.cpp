/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtracking(vector<int>& nums, int startIndex)
    {
        // 第一次进入会把空集压入
        res.push_back(curr);
        if(startIndex == nums.size()) return ;

        for(int i = startIndex; i < nums.size(); i++)
        {
            if(i > startIndex && nums[i] == nums[i - 1]) continue;// 关键的判定语句

            curr.push_back(nums[i]);
            backtracking(nums, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

