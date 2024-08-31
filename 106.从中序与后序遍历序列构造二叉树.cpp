/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
using namespace std;

class Solution {
public:
	TreeNode* traversal(vector<int>& inorder, vector<int>& postorder)
	{
		if(postorder.size() == 0) return nullptr;

		int currRootVal = postorder[postorder.size() - 1]; // the last elem in postorder
		TreeNode* root = new TreeNode(currRootVal);
		if(postorder.size() == 1) return root;
		postorder.pop_back();

		int delimIndex = -1;
		for(int i = 0; i < inorder.size(); ++i)
		{
			if(inorder[i] == currRootVal)
			{
				delimIndex = i;
				break;
			}
		}

		// 区间是左闭右开的
		vector<int> inorderLeft(inorder.begin(), inorder.begin() + delimIndex);
		vector<int> inorderRight(inorder.begin() + delimIndex + 1, inorder.end());
		vector<int> postorderLeft(postorder.begin(), postorder.begin() + inorderLeft.size());
		vector<int> postorderRight(postorder.begin() + inorderLeft.size(), postorder.end());
		root->left = traversal(inorderLeft, postorderLeft);
		root->right = traversal(inorderRight, postorderRight);

		return root;
	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};
// @lc code=end

