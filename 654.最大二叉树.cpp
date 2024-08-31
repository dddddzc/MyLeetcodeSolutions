/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
#include<algorithm>
using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // if(nums.size() == 0) return nullptr;
        if(nums.size() == 1)
        {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }

        int delim = 0;
        int maxVal = nums[0];
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maxVal)
            {
                maxVal = nums[i];
                delim = i;
            }
        }

        TreeNode* root = new TreeNode(maxVal);

        if(delim > 0)
        {
            vector<int> numsLeft(nums.begin(), nums.begin() + delim);
            root->left = constructMaximumBinaryTree(numsLeft);
        }

        if(delim < nums.size() - 1)
        {
            vector<int> numsRight(nums.begin() + delim + 1, nums.end());
            root->right = constructMaximumBinaryTree(numsRight);
        }

        return root;
    }
};
// @lc code=end

