/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    // 有两种形式的旋转数组:
    // 形式1:没有旋转, 0123456
    // 形式2:进行了旋转, 分为两截,456 0123(类似)
    // 需要找到比较的对象, 此处选择第一个数作为比较对象

    int findMin(vector<int>& nums) {
        // 排除形式1
        if(nums[0] < nums[nums.size() - 1] || nums.size() == 1) {
            return nums[0];
        }

        // 形式2, nums[0]一定不是最小值
        int left = 1;
        int right = nums.size() - 1;
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < nums[0]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
// @lc code=end

