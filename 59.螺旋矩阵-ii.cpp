/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;
/*
1. axis
0_ _ _ _ y
|
|
|
x
2. [a,b)
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int circleTimes = 0;
        int num = 1;

        while(circleTimes < n / 2)
        {
            int i = circleTimes; // startX
            int j = circleTimes; // startY
            for(i, j; j < n - circleTimes - 1; ++j)
            {
                matrix[i][j] = num;
                ++num;
            }
            for(i, j; i < n - circleTimes - 1; ++i)
            {
                matrix[i][j] = num;
                ++num;
            }
            for(i, j; j > circleTimes; --j)
            {
                matrix[i][j] = num;
                ++num;
            }
            for(i, j; i > circleTimes; --i)
            {
                matrix[i][j] = num;
                ++num;
            }
            ++circleTimes;
        }

        if(n % 2 == 1)
        {
            matrix[n / 2][n / 2] = n * n;
        }
        return matrix;
    }
};
// @lc code=end

