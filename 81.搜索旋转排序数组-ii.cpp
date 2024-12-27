/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return true;
      }

      if (nums[mid] == nums[left]) {
        // 无法判断哪个区间是有序的,但target位置一定不是left
        left++;
      } else if (nums[mid] == nums[right]) {
        // 无法判断哪个区间是有序的,但target位置一定不是right
        right--;
      } else if (nums[mid] < nums[right]) {
        // 右区间是有序的
        if (target > nums[mid] && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        // 左区间是有序的
        if (target >= nums[left] && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
    }

    return false;
  }
};
// @lc code=end
