/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <climits>
#include <cmath>
#include <cstddef>
#include <limits.h>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    // method 1 : if node val is in region. 
    // bool isValidNode(TreeNode* node, long min, long max) {
    //     if (node == nullptr) {
    //         return true;
    //     }
    //     bool curr = node->val > min && node->val < max;
    //     bool left = isValidNode(node->left, min, node->val);
    //     bool right = isValidNode(node->right, node->val, max);
    //     return curr && left && right;
    // }

    // return isValidNode(root, LONG_LONG_MIN, LONG_LONG_MAX);

    // method 2 : left -- curr -- right, if values are incremented.
    // preVal : record the previous node value.
    // long preVal = LONG_LONG_MIN;
    // bool isValidBST(TreeNode* root) {
    //     if (!root) {
    //         return true;
    //     }
    //     if (!isValidBST(root->left)) {
    //         return false;
    //     }
    //     if (root->val <= preVal) {
    //         return false;
    //     }
    //     preVal = root->val;
    //     return isValidBST(root->right);
    // }

    // method 3 : inverse of method 1
    pair<long long, long long> dfs(TreeNode* node) {
        // 递归到空节点时, 返回区间为 [Inf, -Inf]
        // 这样它上边的叶节点一定是 True 的
        if (node == nullptr) {
            return {LLONG_MAX, LLONG_MIN};
        }

        auto[left_min, left_max] = dfs(node->left);
        auto[right_min, right_max] = dfs(node->right);
        long long x = node->val;

        // 相当于返回了FALSE,递归向上让上面的节点也变成FALSE
        if (x <= left_max || x >= right_min) {
            return {LLONG_MIN, LLONG_MAX};
        }

        return {min(left_min, x), max(right_max, x)};
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root).second != LLONG_MAX;
    }
};
// @lc code=end

