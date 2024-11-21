/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        // 将新区间左侧不相交的区间加入res
        int iter_idx = 0;
        while (iter_idx < intervals.size() && intervals[iter_idx][1] < newInterval[0]) {
            res.push_back(intervals[iter_idx]);
            iter_idx++;
        }

        // 判断当前区间是否与新区间重叠,重叠则持续合并
        // 如果interval = [1, 3] 而 newInterval = [3, 4],则会在这个阶段合并。
        while (iter_idx < intervals.size() && intervals[iter_idx][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[iter_idx][0]);
            newInterval[1] = max(newInterval[1], intervals[iter_idx][1]);
            iter_idx++;
        }
        res.push_back(newInterval);

        // 将新区间右侧不相交的区间加入res
        while (iter_idx < intervals.size()) {
            res.push_back(intervals[iter_idx]);
            iter_idx++;
        }
        
        return res;
    }
};
// @lc code=end

