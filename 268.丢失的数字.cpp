/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = nums.size() * (nums.size() + 1) / 2;
        int realSum = accumulate(nums.begin(), nums.end(), 0);

        return expectedSum - realSum;
    }
};
// @lc code=end

