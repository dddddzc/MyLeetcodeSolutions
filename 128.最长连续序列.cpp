/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 使用 set 去重
        unordered_set<int> numSet;
        for(int& num : nums)
        {
            numSet.insert(num);
        }

        int res = 0;
        for(const int& num : numSet)
        {
            // 0 not present, 1 present
            // 如果 num - 1 存在,则 num 不是最长连续序列的起始,直接忽略
            // 如果 num - 1 不存在,则以 num 为起始向后搜索
            if(!numSet.count(num - 1))
            {
                int currNum = num;
                int currMax = 1;

                while(numSet.count(currNum + 1))
                {
                    currNum++;
                    currMax++;
                }

                res = max(res, currMax);
            }
        }

        return res;
    }
};
// @lc code=end

