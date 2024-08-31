/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> nums12;
        for(auto num1 : nums1)
        {
            for(auto num2 : nums2)
            {
                nums12[num1 + num2]++;
            }
        }

        int count = 0;
        for(auto num3 : nums3)
        {
            for(auto num4 : nums4)
            {
                if(nums12.find(-num3-num4) != nums12.end())
                {
                    count += nums12[-num3-num4];
                }
            }
        }
        return count;
    }
};
// @lc code=end

