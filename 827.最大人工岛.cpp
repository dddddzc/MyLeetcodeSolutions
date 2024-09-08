/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
class Solution {

const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n;

public:
bool in_region(int i, int j)
    {
        return (i >= 0 && i < n && j >= 0 && j < n);
    }

    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int sign)
    {
        int size = 1;
        // 只要能进dfs函数,一定是合法的:在之前进行了合法性判断
        visited[i][j] = sign;
        for(int k = 0; k < 4; k++)
        {
            int next_i = i + dirs[k][0];
            int next_j = j + dirs[k][1];
            if(in_region(next_i, next_j) && grid[next_i][next_j] && !visited[next_i][next_j])
            {
                size += dfs(grid, visited, next_i, next_j, sign);
            }
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0)); // 既是visited,也代表岛屿编号
        
        unordered_map<int, int> areas; // 每个岛屿的面积
        int area = 0;
        int maxArea = 0;
        int sign = 2; // 标记每个1所属岛屿的编号 : 岛屿2 岛屿3 岛屿4......
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] && !visited[i][j]) 
                {
                    area = dfs(grid, visited, i, j, sign);
                    areas[sign] = area;     // 岛屿编号为sign的岛,面积为area
                    sign++;                 // 下一个岛屿sign++
                }
            }
        }

        // 如果全是1
        if(areas.size() == 1 && areas[2] == n * n)
        {
            return areas[2];
        }

        // 现在visited[i][j]即为每个 1 代表的岛屿编号,从2开始
        unordered_set<int> neighbors; // 记录neighbor所属的sign
        int ij_size;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 0) // 只遍历0
                {
                    ij_size = 1;       // 清空
                    neighbors.clear();
                    // 将邻居的sign加入set,实现去重
                    for(int k = 0; k < 4; k++)
                    {
                        int neighbor_i = i + dirs[k][0];
                        int neighbor_j = j + dirs[k][1];
                        if(in_region(neighbor_i, neighbor_j) && grid[neighbor_i][neighbor_j] == 1)
                        {
                            neighbors.insert(visited[neighbor_i][neighbor_j]);  
                        }
                    }
                    for(auto& neighbor_sign : neighbors)
                    {
                        ij_size += areas[neighbor_sign];
                    }
                    maxArea = max(maxArea, ij_size);
                }
            }
        }

        return maxArea;
    }
};
// @lc code=end

