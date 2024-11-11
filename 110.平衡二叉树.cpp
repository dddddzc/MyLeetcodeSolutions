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
#include <algorithm>
class Solution {
public:
    int getDepth(TreeNode* curr) {
        if (!curr) {
            return 0;
        }
        int leftDepth = getDepth(curr->left);
        if (leftDepth == -1) {
            return -1; // 左子树不平衡
        }
        int rightDepth = getDepth(curr->right);
        if (rightDepth == -1) {
            return -1; // 右子树不平衡
        }
        if (std::abs(leftDepth - rightDepth) > 1) {
            return -1; // 左右子树高度不平衡
        }

        return std::max(leftDepth, rightDepth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return getDepth(root) != -1;
    }
};
// @lc code=end

