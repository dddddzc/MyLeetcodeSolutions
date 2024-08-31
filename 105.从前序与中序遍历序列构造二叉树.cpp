/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& preorder, int inorderBegin, int inorderEnd, int preorderBegin, int preorderEnd)
    {
        if(preorderEnd == preorderBegin) return nullptr;

        int currRootVal = preorder[preorderBegin]; // 用preorderBegin, 不要用0
        TreeNode* root = new TreeNode(currRootVal);
        if(preorderEnd - preorderBegin == 1) return root;

        int delimIndex;
        for(delimIndex = inorderBegin; delimIndex < inorderEnd; ++delimIndex)
        {
            if(inorder[delimIndex] == currRootVal)  break;
        }

        // 切割中序数组 [inorderLeftBegin, inorderLeftEnd), [inorderRightBegin, inorderRightEnd)
        int inorderLeftBegin = inorderBegin;
        int inorderLeftEnd = delimIndex;
        int inorderLeftSize = inorderLeftEnd - inorderLeftBegin;
        int inorderRightBegin = delimIndex + 1;
        int inorderRightEnd = inorderEnd;

        // 切割前序数组
        int preorderLeftBegin = preorderBegin + 1;
        int preorderLeftEnd = preorderLeftBegin + inorderLeftSize;
        int preorderRightBegin = preorderLeftEnd;
        int preorderRightEnd = preorderEnd;

        root->left = traversal(inorder, preorder, inorderLeftBegin, inorderLeftEnd, preorderLeftBegin, preorderLeftEnd);
        root->right = traversal(inorder, preorder, inorderRightBegin, inorderRightEnd, preorderRightBegin, preorderRightEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
        return traversal(inorder, preorder, 0, inorder.size(), 0, preorder.size());
    }
};
// @lc code=end

