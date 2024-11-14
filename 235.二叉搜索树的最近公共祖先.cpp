/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        // 如果都在左子树
        if(p->val < root->val && q->val < root->val) {
            ans = lowestCommonAncestor(root->left, p, q);
        }
        // 如果都在右子树
        else if(p->val > root->val && q->val > root->val) {
            ans = lowestCommonAncestor(root->right, p, q);
        }
        // 当前节点就是 p或q, 或者一个在左一个在右
        return ans;
    }
};
// @lc code=end

