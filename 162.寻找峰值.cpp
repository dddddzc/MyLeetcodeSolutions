/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int n = nums.size();
    // 排除特殊情况,即一个元素,或者两端为峰值的情况
    if (n == 1 || nums[0] > nums[1]) {
      return 0;
    }
    if (nums[n - 1] > nums[n - 2]) {
      return n - 1;
    }

    int left = 1;
    int right = n - 2;
    int mid;
    // 如果有峰值,最后left,right,mid都会聚集到峰值上
    while (left <= right) {
      mid = left + (right - left) / 2;
      // 峰值是 mid + 1,或者其右侧的元素
      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
        return mid;
      } else if (nums[mid] > nums[mid - 1]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return -1;
  }
};
// @lc code=end
