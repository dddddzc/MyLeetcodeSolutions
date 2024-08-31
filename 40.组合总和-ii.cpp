/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include<vector>
#include<unordered_set>
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
            if(i > start && candidates[i] == candidates[i - 1]) continue; // 同层去重,精髓！！！
            currRes.push_back(candidates[i]);
            sum += candidates[i];
            reCombination(candidates, target, i + 1);   // 在下层时,start已经更改,因此不影响一条树枝上的重复选取
            currRes.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        reCombination(candidates, target, 0);
        return res;
    }
};
// @lc code=end

