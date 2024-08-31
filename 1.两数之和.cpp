/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myHashMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(myHashMap.find(target - nums[i]) != myHashMap.end())
            {
                return {myHashMap[target - nums[i]], i};
            }
            else
            {
                myHashMap.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};
// @lc code=end

