/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> currRes;
    int currSum = 0;

    void dfs(int k, int n, int startIndex)
    {
        // 大小剪枝
        if(currSum > n) return;
        if(currSum == n && currRes.size() < k) return;

        if(currRes.size() == k)
        {   
            if(currSum == n)    res.push_back(currRes);
            return;
        }

        // 已选 currRes.size() 个, 还差 k - currRes.size()个, 有 9 - i + 1 个可选
        // k - currRes.size() <= 9 - i + 1
        // i <= 10 - (k - currRes.size())
        for(int i = startIndex; i <= 10 - (k - currRes.size()); i++)
        {
            currRes.push_back(i);
            currSum += i;
            dfs(k, n, i + 1);
            currRes.pop_back();
            currSum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return res;
    }
};
// @lc code=end

