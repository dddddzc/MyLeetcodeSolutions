/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    // 初始化并查集
    void init(vector<int>& father)
    {
        for(int i = 1; i < father.size(); i++) father[i] = i;
    }

    // 带有路径压缩的find
    int find(vector<int>& father, int curr)
    {
        if(curr == father[curr]) return curr;
        else return father[curr] = find(father, father[curr]);
    }

    // 合并成功返回0,否则返回-1
    int join(vector<int>& father, int i, int j)
    {
        int fa_i = find(father, i);
        int fa_j = find(father, j);
        if(fa_i == fa_j) return -1;   // i 和 j 已经在一个集合中,不用再join了
        father[fa_i] = fa_j;       // 将 i的祖先的父亲 设置为 j的祖先
        return 0;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> father(edges.size() + 1, 0);
        init(father);
        vector<int> res(2, 0);
        for(const vector<int>& edge : edges)
        {
            if(join(father, edge[0], edge[1]) == -1)
            {
                res = edge;
            }
        }

        return res;
    }
};
// @lc code=end

