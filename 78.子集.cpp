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

    // 答案的角度 : startIndex 代表答案的 curr[startIndex] 选哪个数
    // 每个节点都是答案
    // void backtracking(vector<int>& nums, int startIndex)
    // {
    //     res.push_back(curr);
    //     if(startIndex == nums.size()) return;

    //     for(int i = startIndex; i < nums.size(); i++)
    //     {
    //         curr.push_back(nums[i]);
    //         backtracking(nums, i + 1);
    //         curr.pop_back();
    //     }
    // }

    // 输入的角度 : i 代表 nums[i] 选还是不选
    // 递归到 i == n 时的叶节点才是答案
    void backtracking(vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }

        // 不选,直接跳过第 i 个数
        backtracking(nums, i + 1);

        // 选,选完之后要恢复现场
        curr.push_back(nums[i]);
        backtracking(nums, i + 1);
        curr.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end

