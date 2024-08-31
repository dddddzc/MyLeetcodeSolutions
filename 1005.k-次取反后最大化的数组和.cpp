/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    static bool cmpAbs(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end(), cmpAbs);

        int sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0 && k > 0)
            {
                nums[i] = -nums[i];
                sum += nums[i];
                k--;
            }
            else sum += nums[i];
        }

        if(k % 2 == 0) return sum;
        else if(nums[nums.size() - 1] > 0)
        {
            sum -= 2 * nums[nums.size() - 1];
        }

        return sum;
    }
};
// @lc code=end

