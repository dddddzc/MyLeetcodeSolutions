/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };

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
#include<algorithm>
using namespace std;

class Solution {
public:
    // 递归写法:
    // void recursion(TreeNode* curr, vector<int>& res)
    // {
    //     if(curr == nullptr)
    //     {
    //         return ;
    //     }
    //     if(curr->left) recursion(curr->left, res);
    //     if(curr->right) recursion(curr->right, res);
    //     res.push_back(curr->val);
    // }

    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     recursion(root, res);
    //     return res;
    // }

    // 迭代写法:
    vector<int> postorderTraversal(TreeNode* root) {
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
            s.pop();
            res.push_back(curr->val);
            if(curr->left) s.push(curr->left);
            if(curr->right) s.push(curr->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

