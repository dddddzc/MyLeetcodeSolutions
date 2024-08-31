/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        for(int i = 0; i < gas.size(); i++)
        {
            diff.push_back(gas[i] - cost[i]);
        }

        int start = 0;
        int currSum = 0;
        int totalSum = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            currSum += diff[i];
            totalSum += diff[i];
            if(currSum < 0)
            {
                start = i + 1;
                currSum = 0;
            }
        }

        if(totalSum < 0) return -1;

        return start;
    }
};
// @lc code=end

