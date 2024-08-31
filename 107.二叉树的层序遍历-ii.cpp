/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);

        vector<vector<int>> res;
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
        
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

