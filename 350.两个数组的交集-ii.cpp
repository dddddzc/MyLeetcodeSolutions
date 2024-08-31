/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
        {
            swap(nums1, nums2);
        }
        
        unordered_map<int, int> myHashMap;
        for(int num : nums1)
        {
            ++myHashMap[num];
        }

        vector<int> intersection;
        for(int num : nums2)
        {
            if(myHashMap.find(num) != myHashMap.end())
            {
                intersection.push_back(num);
                --myHashMap[num];
            }
            if(myHashMap[num] == 0) // only use the smaller times.
            {
                myHashMap.erase(num);
            }
        }

        return intersection;
    }
};
// @lc code=end

