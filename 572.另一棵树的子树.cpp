/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
#include<stack>
using namespace std;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        else if(!p || !q) return false;

        stack<TreeNode*> s;
        s.push(p);
        s.push(q);

        while(!s.empty())
        {
            TreeNode* left = s.top();   s.pop();
            TreeNode* right = s.top();  s.pop();  
            
            // 保证left和right都是非nullptr的,否则在后续的push里会出现push(nullptr->left)的情况。
            if(!left && !right) continue; // 不能是return true;
            else if(!left || !right) return false;
            else if(left->val != right->val) return false;

            s.push(left->left);
            s.push(right->left);
            s.push(left->right);
            s.push(right->right);          
        }
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        else if(!root) return false;
        else if(!subRoot) return true;

        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            s.pop();
            if(isSameTree(curr, subRoot))
            {
                return true;
            }

            if(curr->left) s.push(curr->left);
            if(curr->right) s.push(curr->right);
        }
        return false;
    }
};
// @lc code=end

