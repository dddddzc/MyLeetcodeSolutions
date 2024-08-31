/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 没找到
        if(root == nullptr) return root;

        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else
        {
            // 左右都空
            if(!root->left && !root->right)
            {
                delete root;
                return nullptr;
            }
            // 左空右不空
            else if(!root->left)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // 左不空右空
            else if(!root->right)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // 左右都非空
            else
            {
                // 左子树继承
                TreeNode* temp = root->left;
                while(temp->right) temp = temp->right;
                temp->right = root->right;
                
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            }
        }

        return root;
    }
};
// @lc code=end

