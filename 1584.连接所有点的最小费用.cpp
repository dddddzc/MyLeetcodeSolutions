/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        if(n <= 1) return res;

        vector<vector<int>> grid(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++) // 对角线上都是0
            {
                grid[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                grid[j][i] = grid[i][j]; // 无向图,二维矩阵是对称矩阵
            }
        }

        // prim算法需要维护的两个数组
        vector<int> minDist(n, INT_MAX - 1);
        vector<int> visited(n, false);
        // 循环 n - 1 次,每次加入一条边,直到edge_num = n - 1
        for(int edge_num = 1; edge_num <= n - 1; edge_num++)
        {
            int currNode = -1;
            int minVal = INT_MAX; 
            // step1 : 找到下一个距离MST最近的点
            // 第一次循环以第一个点开始初始化MST
            for(int i = 0; i < n; i++)
            {
                // 在集合 U 中寻找,并且其距离需要是最小的
                if(!visited[i] && minDist[i] < minVal)
                {
                    currNode = i;
                    minVal = minDist[i];
                }
            }

            // step2 : 标记当前点为visited,并更新minDist和visited数组
            visited[currNode] = true;
            for(int j = 0; j < n; j++)
            {
                // 如果下标为j的节点与currNode相连
                // 并且没有在集合 V 中
                if(!visited[j] && grid[currNode][j] < minDist[j])
                {
                    minDist[j] = grid[currNode][j];
                }
            }

        }

        for(int i = 1; i < n; i++)
        {
            res += minDist[i]; // 第一个点用于初始化,只有n - 1条边,不加minDist[0](此时其值仍为INT_MAX - 1)
        }

        return res;
    }
};
// @lc code=end

