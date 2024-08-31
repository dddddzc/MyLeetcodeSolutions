/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> robTree(TreeNode* curr)
    {
        if(!curr) return {0, 0};
        vector<int> left = robTree(curr->left);
        vector<int> right = robTree(curr->right);
        
        // val1 : 偷curr节点的最大值
        int val1 = curr->val + left[1] + right[1];

        // val2 : 不偷curr节点的最大值
        int val2 =  max(left[0], left[1]) + max(right[0], right[1]);

        return {val1, val2};
    }

    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
};
// @lc code=end

