/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 选择排序:排序 n - 1 次
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            // 记录第 i 小的值的下标
            int min_idx = i;
            // 从第 i + 1 个数开始遍历,因为前 i 个数已经排好了
            for(int j = i + 1; j < n; j++)
            {
                if(nums[j] < nums[min_idx])
                {
                    min_idx = j;
                }
            }
            swap(nums[i], nums[min_idx]);
        }
    }
};
// @lc code=end

