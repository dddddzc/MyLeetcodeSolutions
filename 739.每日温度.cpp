/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // 栈中存放下标,更简单
        stack<int> st;
        vector<int> res(n, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop(); // 抛弃比当前元素小的栈顶元素
            }
            // 加上非空是为了防止第一个元素,以及st为空时调用st.top()出错
            if(!st.empty()) res[i] = st.top() - i;
            // 先算下标,后push,否则st.top()已经被更改
            st.push(i);
        }

        return res;
    }
};
// @lc code=end

