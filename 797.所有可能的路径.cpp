/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
vector<vector<int>> res;
vector<int> path;

public:
    // x:目前遍历的节点 graph:图
    void dfs(vector<vector<int>>& graph, int x)
    {
        // 当 x = graph.size() - 1 时,说明遍历到了最后一个节点
        if(x == graph.size() - 1)
        {
            res.push_back(path);
            return ;
        }

        for(int i = 0; i < graph[x].size(); i++)
        {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back(); // 回溯!!!
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0); // 从0出发
        dfs(graph, 0);
        return res;
    }
};
// @lc code=end

