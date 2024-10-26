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
    int ge_first(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // 如果写 <, 在left和right指向同一个数的时候就停止了
        // 我们无法知道这个数与target的关系
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1; // 范围缩小到 [mid+1, right]
            } else {
                right = mid - 1;// 范围缩小到 [left, mid-1]
            }
        }

        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0 || nums[0] > target || nums[nums.size() - 1] < target) {
            return {-1, -1};
        } 

        int start = ge_first(nums, target);
        // nums 中不含 target 元素
        if(nums[start] != target) { 
            return {-1, -1};
        }
        // 有start必有end
        int end = ge_first(nums, target + 1) - 1;
        return {start, end};
    }
};
// @lc code=end

