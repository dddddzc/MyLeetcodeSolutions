/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 四个方向
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int& i, int& j, int& row, int& col)
    {
        // 如果触碰到边界,或者非 1,或者遍历过
        if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;

        for(int k = 0; k < 4; k++)
        {
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];
            bfs(grid, visited, next_i, next_j, row, col);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int numLands = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    bfs(grid, visited, i, j, row, col);
                    numLands++;
                }
            }
        }

        return numLands;
    }
};
// @lc code=end

