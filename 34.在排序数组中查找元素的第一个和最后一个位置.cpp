/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    // 找到 target 的第一个位置
    // 或者 大于target的最小数 的第一个位置 
    int lower_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    // 找到 target 的最后一个位置
    // 或者 小于target的最大数 的最后一个位置
    int upper_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            // 此处控制着区间总体向右移动
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty() || nums[0] > target || nums[nums.size() - 1] < target) {
            return {-1, -1};
        } 
        
        // 使用左闭右闭
        int start = lower_bound(nums, target);
        int end = upper_bound(nums, target);
        // start 和 end 搜索到的不一定是 target
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        return {start, end};
    }
};
// @lc code=end

