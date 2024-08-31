/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);

        vector<int> res;
        while(!q.empty())
        {
            int maxVal = INT_MIN;
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                TreeNode* curr = q.front();
                q.pop();
                maxVal = max(maxVal, curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};
// @lc code=end

