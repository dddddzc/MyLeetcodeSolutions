/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> currRes;
    int sum = 0;

    void reCombination(vector<int>& candidates, int target, int start)
    {
        if(sum > target) return;

        if(sum == target)
        {
            res.push_back(currRes);
            return;
        }

        for(int i = start; i < candidates.size(); i++)
        {
            currRes.push_back(candidates[i]);
            sum += candidates[i];
            reCombination(candidates, target, i); // 此处是i,不是i + 1
            currRes.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        reCombination(candidates, target, 0);
        return res;
    }
};
// @lc code=end

