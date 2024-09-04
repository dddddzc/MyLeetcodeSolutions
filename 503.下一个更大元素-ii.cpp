/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start

#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // 存储下标

        for(int i = 0; i < 2 * n; i++)
        {
            int x = nums[i % n];

            while(!st.empty() && x > nums[st.top()])
            {
                res[st.top()] = x;
                st.pop();
            }

            if(i < n) st.push(i);
        }

        return res;
    }
};
// @lc code=end

