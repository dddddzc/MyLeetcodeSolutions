/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include<string>
using namespace std;

class Solution {
public:
    string path2str(vector<int>& path)
    {
        string stringPath;
        for(int i = 0; i < path.size() - 1; ++i)
        {
            stringPath += to_string(path[i]);
            stringPath += "->";
        }
        stringPath += to_string(path[path.size() - 1]);
        return stringPath;
    }

    void traversal(TreeNode* curr, vector<int>& currPath, vector<string>& res)
    {
        currPath.push_back(curr->val);
        if(!curr->left && !curr->right)
        {
            res.push_back(path2str(currPath));
        }
        if(curr->left)
        {
            traversal(curr->left, currPath, res);
            currPath.pop_back(); // 回溯
        }
        if(curr->right)  
        {
            traversal(curr->right, currPath, res);
            currPath.pop_back(); // 回溯
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        vector<int> path;
        traversal(root, path, res);
        return res;
    }
};
// @lc code=end

