/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void insertionSort(vector<int>& arr, int n)
    {
        // 从第 1 个元素开始,假设第 0 个元素已经排序好了
        for(int i = 1; i < n; i++)
        {
            // 选择 arr 中的第 i 个元素
            int num = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > num)
            {
                arr[j + 1] = arr[j];
                j--;
            }

            // 将选中的元素放到正确的位置上
            arr[j + 1] = num;
        }
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        insertionSort(nums, n);
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};
// @lc code=end

