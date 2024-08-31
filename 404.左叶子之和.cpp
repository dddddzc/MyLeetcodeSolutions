/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    bool isLeftChild(TreeNode* curr)
    {
        if(curr->left && !curr->left->left && !curr->left->right)
        {
            return true;
        }
        return false;
    }

    void recursion(TreeNode* curr, int& sum)
    {
        if(!curr) return;

        if(isLeftChild(curr)) sum += curr->left->val;

        recursion(curr->left, sum);
        recursion(curr->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(!root) return sum;

        recursion(root, sum);
        return sum;
    }
};
// @lc code=end

