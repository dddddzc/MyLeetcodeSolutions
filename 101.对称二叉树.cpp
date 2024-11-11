/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool compare(TreeNode* left, TreeNode* right)
    {
        if(!left && !right) return true;
        if(!left || !right) return false;
        return (left->val == right->val) && compare(left->left, right->right) && compare(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return compare(root->left, root->right);
    }
};
// @lc code=end

