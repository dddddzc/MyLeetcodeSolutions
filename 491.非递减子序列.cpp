/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtracking(vector<int>& nums, int startIndex)
    {
        if(curr.size() >= 2) res.push_back(curr); // 不要return, 还可能继续添加元素

        unordered_set<int> used; // 每个used都是该层递归的局部变量,使用set对本层元素进行去重
        // 同一层中
        for(int i = startIndex; i < nums.size(); i++)
        {
            // 如果当前数字比curr中最后一个数小,不用管
            if(!curr.empty() && nums[i] < curr.back()) continue;
            // 如果当前数字已经被用过,不用管
            if(used.find(nums[i]) != used.end()) continue;

            curr.push_back(nums[i]);
            used.insert(nums[i]);
            backtracking(nums, i + 1);
            curr.pop_back();
        }

    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if(nums.empty()) return res;
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

