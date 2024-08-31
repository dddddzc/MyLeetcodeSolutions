/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
class Solution {
public:
    int getDepth(TreeNode* curr)
    {
        if(!curr) return 0;
        int leftDepth = getDepth(curr->left);
        if(leftDepth == -1) return -1;
        int rightDepth = getDepth(curr->right);
        if(rightDepth == -1) return -1;
        if(abs(leftDepth - rightDepth) <= 1)
        {
            return 1 + max(leftDepth, rightDepth);
        }
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int depth = getDepth(root);
        return !(depth == -1);     // -1 would spread to the root.
    }
};
// @lc code=end

