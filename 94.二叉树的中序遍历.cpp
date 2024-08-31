/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // void recursion(TreeNode* curr, vector<int>& res)
    // {
    //     if(curr == nullptr)
    //     {
    //         return ;
    //     }
    //     if(curr->left) recursion(curr->left, res);
    //     res.push_back(curr->val);
    //     if(curr->right) recursion(curr->right, res);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     recursion(root, res);
    //     return res;
    // }

    // 迭代写法:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        // 只有s非空这一个条件是不行的,因为初始就是空的。
        // 遍历结束的条件还有一个:curr指向nullptr(整棵树的最右下节点)。
        while(curr || !s.empty())
        {
            // 只要当前节点有左儿子,就要先将其左儿子压入栈中
            while(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            // 如果有左,则先弹出的是左;否则弹出的是中
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            // 中加入result之后,指针指向右
            curr = curr->right;
        }
        return res;
    }

};
// @lc code=end

