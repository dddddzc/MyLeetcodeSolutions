/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;

        // vector<int> curr(2, 0);
        int left = intervals[0][0];
        int right = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] > right)
            {
                res.push_back(vector<int>{left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else
            {
                // 重叠时合并区间只需要关注右侧,左侧是有序的 left[i] >= left[i - 1]
                right = max(right, intervals[i][1]);
            }
        }

        res.push_back(vector<int>{left, right});
        return res;
    }
};
// @lc code=end

