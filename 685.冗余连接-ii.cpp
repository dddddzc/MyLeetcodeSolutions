/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    // 初始化并查集
    void init(vector<int>& father)
    {
        for(int i = 1; i < father.size(); i++) father[i] = i;
    }

    // 路径压缩的find
    int find(vector<int>& father, int curr)
    {
        if(curr == father[curr]) return curr;
        else return father[curr] = find(father, father[curr]);
    }

    // 合并,如果有环则设置 circle_last_edge;
    void join(vector<int>& father, vector<int>& into, vector<int>& circle_last_edge, int i, int j)
    {
        int fa_i = find(father, i);
        int fa_j = find(father, j);
        if(fa_i == fa_j) 
        {
            circle_last_edge = {i, j}; // i 和 j 已经在一个集合中,记录下形成环的最后一条边
        }
        father[fa_i] = fa_j;       // 将 i的祖先的父亲 设置为 j的祖先
        into[j]++;                 // 更新 j 节点的入度
    }

    // 删去第i条边,看看能不能构成有向树
    bool canBeRemoved(vector<vector<int>>& edges, int remove_i)
    {
        vector<int> father(edges.size() + 1, 0); 
        vector<int> into(edges.size() + 1, 0);    // 计算每个点的入度
        vector<int> circle_last_edge;

        init(father);
        for(int i = 0; i < edges.size(); i++)
        {
            if(i != remove_i) join(father, into, circle_last_edge, edges[i][0], edges[i][1]);
        }

        for(auto& point : into)
        {
            if(point >= 2) return false;
        }

        return circle_last_edge.empty();
    }

    vector<int> find_last_into2(vector<vector<int>>& edges, int point)
    {
        // 从后往前遍历 入度为2的顶点所连接的边, 如果删去它可以形成有向树,它就是要删的边
        for(int i = edges.size() - 1; i >= 0; i--)
        {
            if(edges[i][1] == point && canBeRemoved(edges, i))
                return edges[i];
        }
        return {};
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> father(edges.size() + 1, 0);
        vector<int> into(edges.size() + 1, 0); // 计算每个点的入度
        vector<int> circle_last_edge;
        init(father);
        for(const vector<int>& edge : edges)
        {
            join(father, into, circle_last_edge, edge[0], edge[1]);
        }

        // join完之后,寻找是否有入度为2的点
        for(int i = 1; i <= edges.size(); i++)
        {
            if(into[i] == 2) return find_last_into2(edges, i); // i是顶点下标
        }

        // 没有入度为2的顶点, 删除最后一条构成环的边
        return circle_last_edge;
    }
};
// @lc code=end

