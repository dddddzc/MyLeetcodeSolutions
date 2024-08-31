/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool traversal(TreeNode* curr, int targetSum)
    {
        targetSum -= curr->val;
        // 找到合适的叶子节点
        if(!curr->left && !curr->right && targetSum == 0) return true;
        // 找到了合适的则立刻向上返回
        if(curr->left && traversal(curr->left, targetSum)) return true;
        if(curr->right && traversal(curr->right, targetSum)) return true;
        // 此处的return false只会在遍历完所有路径且无合适路径时才会触发
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return traversal(root, targetSum);
    }
};
// @lc code=end

