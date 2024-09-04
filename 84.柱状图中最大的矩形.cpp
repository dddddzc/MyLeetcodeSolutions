/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st1;
        stack<int> st2;

        // 计算 left[i] : heights[i] 左侧第一个比它小的元素下标 
        for(int i = 0; i < n; i++)
        {
            while(!st1.empty() && heights[i] <= heights[st1.top()])
            {
                st1.pop();
            }

            if(!st1.empty()) left[i] = st1.top();

            st1.push(i);
        }


        // 计算 right[i] : heights[i] 右侧第一个比它小的元素下标 
        for(int i = 0; i < n; i++)
        {
            while(!st2.empty() && heights[i] < heights[st2.top()])
            {
                right[st2.top()] = i;
                st2.pop();
            }

            st2.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;

    }
};
// @lc code=end

