/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int minDiff = __INT_MAX__;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* curr)
    {
        if(curr == nullptr) return;

        traversal(curr->left);

        if(pre != nullptr) minDiff = min(curr->val - pre->val, minDiff);
        pre = curr;

        traversal(curr->right);
    }

    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return minDiff;
    }
};
// @lc code=end

