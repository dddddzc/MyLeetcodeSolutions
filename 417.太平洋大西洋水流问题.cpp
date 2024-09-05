/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
int m = 0;
int n = 0;
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; // 四个方向
public:
    bool in_region(int i, int j)
    {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& flag, int i, int j)
    {
        flag[i][j] = true;

        for(int k = 0; k < 4; k++)
        {
            int next_i = i + dir[k][0];
            int next_j = j + dir[k][1];

            if(in_region(next_i, next_j) && !flag[next_i][next_j] && heights[next_i][next_j] >= heights[i][j]) //逆流而上
            {
                bfs(heights, flag, next_i, next_j);
            }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> visited1(m, vector<bool>(n, false)); // 左上出发
        vector<vector<bool>> visited2(m, vector<bool>(n, false)); // 右下出发

        for(int i = 0; i < n; i++) // 遍历第一行和最后一行
        {
            bfs(heights, visited1, 0 , i);       // 第一行第i个
            bfs(heights, visited2, m - 1 , i);   // 最后一行第i个
        }
        for(int i = 0; i < m; i++) // 遍历第二行到倒数第二行的第一格和最后一格
        {
            bfs(heights, visited1, i , 0);      // 第i行第一个
            bfs(heights, visited2, i, n - 1);   // 第i行最后一个
        }

        // 查找被 bfs 过两次的点
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited1[i][j] && visited2[i][j])
                {
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};
// @lc code=end

