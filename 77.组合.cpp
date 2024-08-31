/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> totalRes;
    vector<int> currRes;
    void dfs(int n, int k, int startIndex)
    {
        if(currRes.size() == k) 
        {
            totalRes.push_back(currRes);
            return;
        }
        // 当前已选 currRes.size() 个,还差 k - currRes.size()个
        // 从当前开始还剩的元素个数为: n - i + 1 个
        // 所以剪枝判断: n - i + 1 >= k - currRes.size()
        // 即:i <= n + 1 - (k - currRes.size())
        for(int i = startIndex; i <= n + 1 - (k - currRes.size()); i++)
        {
            currRes.push_back(i);
            dfs(n, k, i + 1);
            currRes.pop_back(); // 回溯的关键!
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return totalRes;
    }
};
// @lc code=end

