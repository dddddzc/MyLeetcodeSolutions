/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include<vector>
#include<iostream>
using namespace std;

// numbers    : 0 1 2 1 0
// left2right : 1 2 3 1 1
// right2left : 1 2 3 2 1

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candys(n,1);
        int count = n;

        for(int i = 1; i < n; i++)
        {
            if(ratings[i] > ratings[i - 1])
            {
                candys[i] = candys[i - 1] + 1;
                count += candys[i - 1];
            }
        }
        for(int i = n - 1; i >= 1; i--)
        {
            if(ratings[i - 1] > ratings[i] && candys[i - 1] <= candys[i])
            {
                count += candys[i] + 1 - candys[i - 1];
                candys[i - 1] = candys[i] + 1;
            }
        }

        return count;
    }
};
// @lc code=end

