/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void dfs(vector<int>& nums, vector<int>& used)
    {
        if(curr.size() == nums.size())
        {
            res.push_back(curr);
            return ;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            // 当前数被用过,跳过
            if(used[i] == 1) continue;
            // 当前数与前一个数相同,并且前一个数未被used,说明前一个数已经走完了遍历,跳过
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0) continue;

            used[i] = 1;
            curr.push_back(nums[i]);
            dfs(nums, used);
            curr.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> used(8, 0);
        dfs(nums, used);
        return res;
    }
};
// @lc code=end

