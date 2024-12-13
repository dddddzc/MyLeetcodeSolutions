/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)   return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> currLayer;
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode* curr = q.front();
                q.pop();
                currLayer.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(currLayer);
        }
        return res;
    }
};
// @lc code=end

