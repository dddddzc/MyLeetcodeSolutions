/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int currCount = 0;
    int maxCount = 0;
    TreeNode* pre = nullptr;
    vector<int> res;

    void traversal(TreeNode* curr, vector<int>& res)
    {
        if(curr == nullptr) return;

        traversal(curr->left, res);

        if(pre == nullptr)
        {
            currCount = 1;
            maxCount = 1;
        }
        else if(curr->val == pre->val) currCount++;
        else currCount = 1;
        
        pre = curr;

        if(currCount == maxCount)
        {
            res.push_back(curr->val);
        }
        else if(currCount > maxCount)
        {
            maxCount = currCount;
            res.clear();
            res.push_back(curr->val);
        }

        traversal(curr->right, res);
    }

    vector<int> findMode(TreeNode* root) {
        traversal(root, res);
        return res;
    }
};
// @lc code=end

