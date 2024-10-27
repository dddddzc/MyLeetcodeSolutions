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
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        // 此处是 < 而不是 <=
        // 因为在找到峰值的前一次比较,L与R就在峰值和峰值的邻居上
        // 比完最后一次大小之后,L R都在峰值的位置上了,就找到了,不用再比
        // 所以最后return的时候 left right 都可以
        while (left < right) {
            mid = left + (right - left) / 2;
            // 峰值是 mid + 1,或者其右侧的元素
            if(nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else { // 峰值是 mid,或者其左侧的元素 
                right = mid;
            }
        }

        return right;
    }
};
// @lc code=end

