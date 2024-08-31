/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        if(root) q.push(root);

        vector<vector<int>> res;
        while(!q.empty())
        {
            vector<int> currLayer;
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                Node* curr = q.front();
                q.pop();
                currLayer.push_back(curr->val);
                for(auto n : curr->children)
                {
                    q.push(n);
                }
            }
            res.push_back(currLayer);
        }
        return res;     
    }
};
// @lc code=end

