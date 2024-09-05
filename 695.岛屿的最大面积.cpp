/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start

#include<vector>
using namespace std;

class Solution {
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 四个方向

public:
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int& i, int& j, int& row, int& col)
    {
        visited[i][j] = true;
        int area = 1;

        for(int k = 0; k < 4; k++)
        {
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            if(next_i >= 0 && next_i < row && next_j >= 0 && next_j < col && grid[next_i][next_j] == 1 && !visited[next_i][next_j])
            {
                area += bfs(grid, visited, next_i, next_j, row, col);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        int maxArea = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    area = bfs(grid, visited, i, j, m, n);
                    maxArea = max(area, maxArea);
                }
            }
        }

        return maxArea;
    }
};
// @lc code=end

