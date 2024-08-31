/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if(points.empty())
        {
            return 0;
        }
        if(points.size() == 1)
        {
            return 1;
        }
        
        // 按照左边界排序
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b)
        {
            return a[0] < b[0];
        });       

        // 寻找有overlap的区间,如果overlap，则将当前区间设置为交集，
        // 并继续向后查找，直到没有overlap，此时发射一次，count++
        // 之后重复这种做法
        // 注意最后的边界处count处理
        int count = 0;
        for (int i = 1; i < points.size(); i++)
        {
            // 如果当前区间左边界大于上一个区间右边界,发射
            if(points[i][0] > points[i - 1][1]) count++;
            // 当前区间左边界在上一个区间右边界左侧
            else points[i][1] = min(points[i - 1][1], points[i][1]);
        }

        return count + 1;
    }
};
// @lc code=end