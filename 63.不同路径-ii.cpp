/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int k = 0; k < n && obstacleGrid[0][k] == 0; k++) dp[0][k] = 1;
        for(int l = 0; l < m && obstacleGrid[l][0] == 0; l++) dp[l][0] = 1;

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(!obstacleGrid[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        } 

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

