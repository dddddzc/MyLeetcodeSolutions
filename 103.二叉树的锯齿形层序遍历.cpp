/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        bool nextLayerEven = true;
        while (!q.empty()) {
            vector<int> currLayer;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* qfront = q.front();
                q.pop();
                currLayer.push_back(qfront->val);
                if(qfront->left) q.push(qfront->left);   
                if(qfront->right) q.push(qfront->right);
            }
            // 添加该层元素进入res,如果为偶数层则翻转
            if (!nextLayerEven) {
                reverse(currLayer.begin(), currLayer.end());
            }
            res.push_back(currLayer);
            nextLayerEven = !nextLayerEven;
        }
        return res;
    }
};
// @lc code=end

