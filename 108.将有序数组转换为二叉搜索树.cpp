/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<vector>
using namespace std;

class Solution {
public:
    TreeNode* toBst(vector<int>& nums, int begin, int end)
    {
        int size = end - begin;
        TreeNode* curr = nullptr;

        if(size == 0) return curr;
        else if(size == 1) curr = new TreeNode(nums[begin]);
        else
        {
            int currIndex = begin + size / 2;
            curr = new TreeNode(nums[currIndex]);
            curr->left = toBst(nums, begin, currIndex);
            curr->right = toBst(nums, currIndex + 1, end);
        }
        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBst(nums, 0, nums.size());
    }
};
// @lc code=end

