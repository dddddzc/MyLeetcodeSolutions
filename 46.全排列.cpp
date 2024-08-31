/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;

    void backtracking(vector<int>& num, int startIndex)
    {
        if(startIndex == num.size() - 1)
        {
            res.push_back(num);
            return;
        }

        for(int i = startIndex; i < num.size(); i++)
        {
            swap(num[i], num[startIndex]);
            backtracking(num, startIndex + 1);
            swap(num[i], num[startIndex]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return res;
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

