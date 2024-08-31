// @before-stub-for-debug-begin
#include<iostream>
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start_color = image[sr][sc];
        if (color != start_color)
        {
            DFS(image, sr, sc, color, start_color);
        }
        return image;
    }

    void DFS(vector<vector<int>>&image, int i, int j, int color, int start_color)
    {
        if( is_valid(image, i, j, start_color) && image[i][j] == start_color)
        {
            image[i][j] = color;
            DFS(image, i - 1, j, color, start_color);
            DFS(image, i + 1, j, color, start_color);
            DFS(image, i, j - 1, color, start_color);
            DFS(image, i, j + 1, color, start_color);
        }
    }

    bool is_valid(vector<vector<int>>&image, int i, int j, int start_color)
    {
        int m = image.size();
        int n = image[0].size();
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
};
// @lc code=end

