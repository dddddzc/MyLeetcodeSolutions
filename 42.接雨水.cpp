/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int res = 0;
    int n = height.size();

    int left = 0;
    int right = n - 1;

    int pre_max = height[0];
    int suf_max = height[n - 1];

    while (left <= right) {
      // 更新当前前后缀
      pre_max = max(pre_max, height[left]);
      suf_max = max(suf_max, height[right]);
      if (pre_max <= suf_max) {
        res += pre_max - height[left];
        left++;
      } else {
        res += suf_max - height[right];
        right--;
      }
    }

    return res;
  }
};
// @lc code=end
