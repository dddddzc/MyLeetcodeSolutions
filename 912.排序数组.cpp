/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        // create a temporary array
        vector<int> tmp(right - left + 1);
        // index for left subarray 
        int i = left;
        // index for right subarray 
        int j = mid + 1; 

        // index for temporary array
        int k = 0; 
        while (i <= mid && j <= right) 
        {
            // increment the left pointer 
            // if the right pointer element is bigger 
            // Since we are sorting in ascending order,left(smaller element) goes first
            if(nums[i] <= nums[j]) 
            {
                tmp[k] = nums[i];   
                i++;
                k++;
            }
            else 
            {
                tmp[k] = nums[j];
                j++;
                k++;
            }
        }

        // Since in the above while loop if one condition stop satisfying loop breaks 
        // Then we need to take care of  next / remaining  elements  
        // Hence adding remaining elements of left half
        while (i <= mid) tmp[k++] = nums[i++];
        // adding remaining elements of right half
        while (j <= right) tmp[k++] = nums[j++]; 

        // Copy data to nums
        for (i = 0; i < k; i++) nums[left + i] = tmp[i];
    }

    void mergeSort(vector<int>& arr, int left, int right)
    {
        // 只剩一个元素时, left == right
        if(left == right) return;

        // 不止一个元素,分治!
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end

