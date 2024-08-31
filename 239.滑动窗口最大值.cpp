/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> index; //维护下标
        vector<int> res;

        for(int i = 0; i < n; ++i)
        {
            while(!index.empty() && nums[i] >= nums[index.back()])
            {
                index.pop_back();
            }

            index.push_back(i);
            
            if(i - index.front() >= k)
            {
                index.pop_front();
            }

            if(i >= k - 1)
            {
                res.push_back(nums[index.front()]);
            }
        }

        return res;
    }
};
// @lc code=end

