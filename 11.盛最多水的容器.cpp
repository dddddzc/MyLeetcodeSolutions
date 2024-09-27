/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right)
        {
            int curr = (right - left) * min(height[left], height[right]);
            res = max(res, curr);
            height[left] <= height[right] ? left++ : right--;
        }
        return res;
    }
};
// @lc code=end

