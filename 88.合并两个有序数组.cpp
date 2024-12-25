/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    if (m == 0) {
      nums1 = nums2;
    }
    for (int i = m - 1, j = n - 1; i >= 0 && j >= 0;) {
      // 依次比较末尾的数谁大，然后往 num1 从后向前塞
      if (nums2[j] >= nums1[i]) {
        nums1[i + j + 1] = nums2[j];
        --j;
      } else {
        nums1[i + j + 1] = nums1[i];
        --i;
      }

      // 如果 nums2 已经用完了,而 nums1 还没遍历完, 则 nums1 已经有序,正常结束
      // 如果 num1 已经用完了,但 nums2 还没用完, 则要将 nums2 剩下的数挪到 num1
      // 的前边
      if (i == -1 && j >= 0) {
        while (j >= 0) {
          nums1[j] = nums2[j];
          j--;
        }
      }
    }
  }
};
// @lc code=end
