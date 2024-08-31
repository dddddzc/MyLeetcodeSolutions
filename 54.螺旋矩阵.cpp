/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        if(matrix.empty())
        {
            return output;
        }
        int upperBound = 0;
        int lowerBound = matrix.size() - 1;
        int leftBound = 0;
        int rightBound = matrix[0].size() - 1;

        while(1)
        {
            for(int i = leftBound; i <= rightBound; ++i)
            {
                output.push_back(matrix[upperBound][i]);
            }
            upperBound++;
            if(upperBound > lowerBound)
            {
                break;
            }

            for(int i = upperBound; i <= lowerBound; ++i)
            {
                output.push_back(matrix[i][rightBound]);
            }
            rightBound--;
            if(rightBound < leftBound)
            {
                break;
            }

            for(int i = rightBound; i >= leftBound; --i)
            {
                output.push_back(matrix[lowerBound][i]);
            }
            lowerBound--;
            if(lowerBound < upperBound)
            {
                break;
            }

            for(int i = lowerBound; i >= upperBound; --i)
            {
                output.push_back(matrix[i][leftBound]);
            }
            leftBound++;
            if(leftBound > rightBound)
            {
                break;
            }
        }

        return output;
    }
};
// @lc code=end

