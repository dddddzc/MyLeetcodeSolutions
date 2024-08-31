/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    void traversal(TreeNode* curr, int targetSum, vector<int>& currPath, vector<vector<int>>& res)
    {
        currPath.push_back(curr->val);
        targetSum -= curr->val;
        // 结束条件
        if(!curr->left && !curr->right && targetSum == 0) res.push_back(currPath);
    
        if(curr->left) traversal(curr->left, targetSum, currPath, res);
        if(curr->right) traversal(curr->right, targetSum, currPath, res);
        currPath.pop_back(); // 注意回溯的位置!
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root) return res;

        vector<int> path;
        traversal(root, targetSum, path, res);
        return res;
    }
};
// @lc code=end

