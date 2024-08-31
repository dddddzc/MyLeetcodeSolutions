/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        vector<int> ge, eq, le;
        int pivot = nums[0];
        for (int num : nums)
        {
            if (num < pivot)
            {
                le.push_back(num);
            }
            if (num == pivot)
            {
                eq.push_back(num);
            }   
            if (num > pivot)
            {
                ge.push_back(num);
            }      
        }
        if (k <= ge.size())
        {
            return findKthLargest(ge, k);
        }

        if (k > ge.size() && k <= ge.size() + eq.size())
        {
            return pivot;
        }
        else
        {
            return findKthLargest(le, k - ge.size() - eq.size());
        }
    }
};
// @lc code=end

