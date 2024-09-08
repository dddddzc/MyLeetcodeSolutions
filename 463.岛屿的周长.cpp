/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int land = 0;
        int border = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1)
                {
                    land++;
                    if(i + 1 < row && grid[i + 1][j] == 1) border++;
                    if(j + 1 < col && grid[i][j + 1] == 1) border++;
                }
            }
        }

        return 4 * land - 2 * border;
    }
};
// @lc code=end

