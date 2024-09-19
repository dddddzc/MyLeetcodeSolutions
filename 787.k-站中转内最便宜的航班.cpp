/*
 * @lc app=leetcode.cn id=787 lang=cpp
 *
 * [787] K 站中转内最便宜的航班
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int UpperBound = INT_MAX / 2;
        // minDist[i][j] : 经过i条边,点j到源点的最短距离
        vector<vector<int>> minDist(k + 2, vector<int>(n, UpperBound));
        // 经过0条边, 节点 src 开始
        minDist[0][src] = 0;

        // k站中转, 经过 k + 1 条边
        for(int i = 1; i <= k + 1; i++)
        {
            for(auto& flight : flights)
            {
                // from : flight[0]
                // to : flight[1]
                // dist : flight[2]
                if(minDist[i - 1][flight[0]] + flight[2] < minDist[i][flight[1]])
                {
                    minDist[i][flight[1]] = minDist[i - 1][flight[0]] + flight[2];
                }
            }
        }

        int res = UpperBound;
        // 在 经过1条边,经过2条边...经过 k + 1 条边 中遍历
        // 得到最k站中转最便宜的航班
        for(int i = 1; i <= k + 1; i++)
        {
            res = min(res, minDist[i][dst]);
        }
        return res == UpperBound ? -1 : res;
    }
};
// @lc code=end

