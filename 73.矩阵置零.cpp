/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // 使用两个一维数组记录哪些行和列需要置零
        // 共占用O(m+n)的空间
        vector<bool> row0(m, false);
        vector<bool> col0(n, false);

        // 遍历矩阵，记录哪些行和列需要置零
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row0[i] = true;
                    col0[j] = true;
                }
            }
        }

        // 遍历矩阵，根据记录的行和列置零信息，将矩阵置零
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row0[i] == true || col0[j] == true){
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
// @lc code=end

