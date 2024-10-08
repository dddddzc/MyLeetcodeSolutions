/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start

#include<vector>
#include<stack>
using namespace std;

// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int depth = 0; 
        for(auto c : root->children)
        {
            depth = max(depth, maxDepth(c));
        }
        return depth + 1;
    }
};
// @lc code=end

