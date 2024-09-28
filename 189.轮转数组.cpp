/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) return;
        // 保证 k < n
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
// @lc code=end

