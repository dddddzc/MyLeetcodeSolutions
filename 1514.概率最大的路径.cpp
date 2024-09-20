/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 */

// @lc code=start
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // 数组 + list 构建邻接表,每个pair为 {to, prob}
        vector<list<pair<int, double>>> adjList(n);
        for(int i = 0; i < edges.size(); i++)
        {
            // 无向图
            adjList[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adjList[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        
        // 使用 SPFA 算法
        vector<double> maxProb(n, 0);
        vector<bool> inQueue(n, false);
        queue<int> q;

        // 初始化
        maxProb[start_node] = 1;
        inQueue[start_node] = true;
        q.push(start_node);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            inQueue[curr] = false; // 清除在队列中的标记

            for(auto& edge : adjList[curr])
            {
                int to = edge.first;
                double prob = edge.second;

                if(maxProb[curr] * prob > maxProb[to])
                {
                    maxProb[to] = maxProb[curr] * prob;
                    if(!inQueue[to]) // 只添加目前不在queue中的元素
                    {
                        q.push(to);
                        inQueue[to] = true;
                    }
                }
            }
        }

        return maxProb[end_node];
    }
};
// @lc code=end

