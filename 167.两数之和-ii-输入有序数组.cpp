/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> idx(2, 0);
        for (int i = 0, j = numbers.size() - 1; ; )
        {
            if(numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else if (numbers[i] + numbers[j] < target)
            {
                i++;
            }
            else
            {
                idx[0] = i + 1;
                idx[1] = j + 1;
                break;
            } 
        }
        return idx;
    }
};
// @lc code=end

