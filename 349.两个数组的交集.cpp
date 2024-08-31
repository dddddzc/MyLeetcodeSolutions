/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int num : nums2)
        {
            if(nums_set.find(num) != nums_set.end())
            {
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
// @lc code=end

