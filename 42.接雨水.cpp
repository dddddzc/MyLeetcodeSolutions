/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> st; // 记录下标,下标可以用来算宽度

        for(int i = 0; i < height.size(); i++)
        {
            // 遇上比栈顶高的元素
            while(!st.empty() && height[i] >= height[st.top()])
            {
                int bottom_height = height[st.top()];
                st.pop();

                if(st.empty()) break; // 例如数组元素起始为 0 1, 这里是接不了雨水的,因为找不到左边的柱子

                int left = st.top();  // 或者说在获取left = st.top() 之前要先保证栈非空
                int h = min(height[i], height[left]) - bottom_height;
                int width = i - left - 1;
                res += width * h;
            }

            st.push(i); // 比当前栈顶元素小,压入
        }

        return res;
    }
};
// @lc code=end

