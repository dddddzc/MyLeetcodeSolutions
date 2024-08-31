/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /*
        Method 1: greedy
        */
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
        {
            return a[1] < b[1];
        });
        
        int erase_count = 0;
        int right_bound = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if ( intervals[i][0] < right_bound ) erase_count++;
            else right_bound = intervals[i][1];
        }
        return erase_count;
    }
        /*
        Method 2:Dynamic Programming
        */
        
        // if(intervals.empty())
        // {
        //     return 0;
        // }

        // sort(intervals.begin(), intervals.end(), [](const auto&u, const auto& v)
        // {
        //     return u[0] < v[0];
        // });

        // int n = intervals.size();
        // vector <int> f(n, 1);
        // for (int i = 1; i < n; i++)
        // {
        //     for (int j = i - 1; j >= 0; j--)
        //     {
        //         if (intervals[j][1] <= intervals[i][0])
        //         {
        //             f[i] = max(f[i], f[j] + 1);
        //         }
        //     }
        // }
        
        // return (n - *max_element(f.begin(), f.end()) );
};
// @lc code=end

