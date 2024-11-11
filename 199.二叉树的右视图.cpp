/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    void recursiveRightMost(TreeNode* curr, int depth, vector<int>& ans) {
        if (!curr) {
            return;
        }
        if (curr && depth == ans.size()) {
            ans.push_back(curr->val);
        }
        recursiveRightMost(curr->right, depth + 1, ans);
        recursiveRightMost(curr->left, depth + 1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursiveRightMost(root, 0, ans);
        return ans;
        // queue<TreeNode*> q;
        // if(root) q.push(root);

        // vector<int> res;
        // while(!q.empty())
        // {
        //     int size = q.size();
        //     for(int i = 0; i < size; ++i)
        //     {
        //         TreeNode* curr = q.front();
        //         q.pop();
        //         if(i == size- 1) res.push_back(curr->val);
        //         if(curr->left) q.push(curr->left);
        //         if(curr->right) q.push(curr->right);
        //     }
        // }
        // return res;
    }
};
// @lc code=end

