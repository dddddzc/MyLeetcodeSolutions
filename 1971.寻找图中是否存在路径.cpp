/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start

#include<vector>
using namespace std;

class Solution {
public:
    void init(vector<int>& father)
    {
        for(int i = 0; i < father.size(); i++) father[i] = i;
    }

    int find(vector<int>& father, int curr)
    {
        if(curr == father[curr]) return curr;
        else return father[curr] = find(father, father[curr]);
    }

    void join(vector<int>& father, int i, int j)
    {
        int fa_i = find(father, i);
        int fa_j = find(father, j);
        if(fa_i == fa_j) return;   // i 和 j 已经在一个集合中,不用再join了
        father[fa_i] = fa_j;       // 将 i的祖先的父亲 设置为 j的祖先
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> father(n);
        init(father);
        for(auto& edge : edges)
        {
            join(father, edge[0], edge[1]);
        }

        return (find(father, source) == find(father, destination));
    }
};
// @lc code=end

