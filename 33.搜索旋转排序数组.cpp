/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 排除nums只有0个或1个元素的情况
        if (nums.size() == 0 || (nums.size() == 1 && nums[0] != target)) {
            return -1;
        }

        // 仍然以第一个数作为比较对象
        if(nums[0] == target) {
            return 0;
        }

        int left = 1;
        int right = nums.size() - 1;
        int mid;
        if (nums[0] < target) { // target在第一段
            // while需要 <=, 因为如果是严格 <, 在left = right时就退出循环了
            // 我们无法知道此时的nums[left] = nums[right]是否等于target 
            while (left <= right) {
                mid = left + (right - left) / 2;
                if(nums[mid] == target) {
                    return mid;
                }

                // 原始
                // if(nums[mid] < nums[0]) {
                //     right = mid - 1;
                // } else if (nums[mid] > nums[0]) {
                //     if(nums[mid] > target) {
                //         right = mid - 1;
                //     } else {
                //         left = mid + 1;
                //     }
                // }

                // 精简
                if(nums[mid] > nums[0] && nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }   
        } 
        
        if (nums[0] > target) {  // target在第二段
            while (left <= right) {
                mid = left + (right - left) / 2;
                if(nums[mid] == target) {
                    return mid;
                }

                // 原始
                // if(nums[mid] > nums[0]) {
                //     left = mid + 1;
                // } else if (nums[mid] < nums[0]) {
                //     if(nums[mid] < target) {
                //         left = mid + 1;
                //     } else {
                //         right = mid - 1;
                //     }
                // }

                // 精简
                if(nums[mid] < nums[0] && nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }           
        }

        return -1;
    }
};
// @lc code=end

