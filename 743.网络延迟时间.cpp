/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

// 小顶堆
class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int UpperBound = INT_MAX / 2;
        // 下标 i 代表序号为 i + 1 的节点
        vector<vector<int>> grid(n, vector<int>(n, UpperBound));
        for(auto& time : times)
        {
            grid[time[0] - 1][time[1] - 1] = time[2];
        }

        // 存储从源点到每个节点的最短距离
        std::vector<int> minDist(n, UpperBound);

        // 优先队列中存放 pair<节点，源点到该节点的距离>
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;
        // 初始化队列，源点到源点的距离为0，所以初始为0
        minDist[k - 1] = 0;
        pq.push(pair<int, int>(k - 1, 0));

        while (!pq.empty()) 
        {
            // 1.选距离源点最近且未访问过的节点
            pair<int, int> curr = pq.top(); 
            pq.pop();

            // 2.标记该节点已被访问
            // 如果curr.second > minDist[curr.first],说明已经出堆过,直接跳过
            if(curr.second > minDist[curr.first]) continue;

            // 3.更新非访问节点到源点的距离（即更新minDist数组）
            for (int i = 0; i < n; i++) 
            {
                if (grid[curr.first][i] != UpperBound && minDist[curr.first] + grid[curr.first][i] < minDist[i]) 
                {
                    minDist[i] = minDist[curr.first] + grid[curr.first][i];
                    pq.push(pair<int, int>(i, minDist[i]));
                }
            }
        }

        return *max_element(minDist.begin(), minDist.end()) == UpperBound ? -1 : *max_element(minDist.begin(), minDist.end());
    }
};
// @lc code=end

