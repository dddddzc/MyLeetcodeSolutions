/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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

class Solution {
public:
    int recursive_depth(TreeNode* curr) {
        if(curr == nullptr) {
            return 0;
        }
        int left_depth = recursive_depth(curr->left);
        int right_depth = recursive_depth(curr->right);
        return max(left_depth, right_depth) + 1;
    }
    int maxDepth(TreeNode* root) {
        // queue<TreeNode*> q;
        // int depth = 0;
        // if(root) q.push(root);

        // while(!q.empty())
        // {
        //     int size = q.size();
        //     for(int i = 0; i < size; ++i)
        //     {
        //         TreeNode* curr = q.front();
        //         q.pop();
        //         if(curr->left) q.push(curr->left);
        //         if(curr->right) q.push(curr->right);
        //     }
        //     depth++;
        // }
        // return depth;
        return recursive_depth(root);
    }
};
// @lc code=end

