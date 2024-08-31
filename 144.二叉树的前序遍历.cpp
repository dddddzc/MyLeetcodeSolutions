/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    // 递归写法:
    // void recursion(TreeNode* curr, vector<int>& result)
    // {
    //     if(curr == nullptr)
    //     {
    //         return ;
    //     }

    //     result.push_back(curr->val);
    //     recursion(curr->left, result);
    //     recursion(curr->right, result);
    // }

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     recursion(root, res);
    //     return res;
    // }

    // 迭代写法:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
        {
            return res;
        }

        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            if(curr) res.push_back(curr->val);
            s.pop();

            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }

        return res;
    }
};
// @lc code=end

