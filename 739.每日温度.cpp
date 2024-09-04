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
        // method 1 : 从右向左遍历
        // int n = temperatures.size();
        // vector<int> res(n, 0);
        // stack<int> st;

        // for(int i = n - 1; i >= 0; i--)
        // {
        //     // 去除栈顶比当前元素小的元素
        //     while(!st.empty() && temperatures[i] >= temperatures[st.top()])
        //     {
        //         st.pop();
        //     }
        //     // 栈中还存在比当前元素大的元素,则为其后第一个比它大的元素
        //     if(!st.empty()) res[i] = st.top() - i;
        //     st.push(i);
        // }
        // return res;


        // method 2 : 从左向右遍历
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }

            st.push(i);
        }

        return res;
    }
};
// @lc code=end

