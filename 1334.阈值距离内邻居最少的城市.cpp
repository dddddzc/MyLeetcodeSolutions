/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 *
 * [1334] 阈值距离内邻居最少的城市
 */

// @lc code=start

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int UB = INT_MAX / 2;
        vector<vector<int>> grid(n, vector<int>(n, UB));

        // 初始化grid : 无向图
        for(auto& edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int dist = edge[2];
            grid[from][to] = dist;
            grid[to][from] = dist;
        }
        for(int i = 0; i < n; i++)
        {
            grid[i][i] = 0;
        }

        // 开始floyd
        for(int k = 0; k < n; k++) // 加入 n 个结点
        {
            for(int i = 0; i < n; i++)
            {
                if(i == k) continue;
                for(int j = i + 1; j < n; j++) // j 从 i + 1 开始,而非 0 开始,是因为无向图
                {
                    if(j == k) continue;
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                    grid[j][i] = grid[i][j];
                }
            }
        }

        int city = -1;
        int min_count = UB;
        for(int i = 0; i < n; i++) // 枚举 n 个城市,找出小于distanceThreshold的邻居最少的城市
        {
            int curr_count = 0;
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] <= distanceThreshold) curr_count++;
            }

            if(curr_count <= min_count)
            {
                city = i;
                min_count = curr_count;
            }
        }
        return city;
    }
};
// @lc code=end

