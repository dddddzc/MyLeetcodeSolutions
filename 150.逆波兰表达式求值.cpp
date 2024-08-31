/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numStack;
        for(string s : tokens)
        {
            if(s == "+" || s == "-" || s == "*" || s == "/")
            {
                int num1 = numStack.top();
                numStack.pop();
                int num2 = numStack.top();
                numStack.pop();
                if(s == "+") numStack.push(num2 + num1);
                if(s == "-") numStack.push(num2 - num1);
                if(s == "*") numStack.push(num2 * num1);
                if(s == "/") numStack.push(num2 / num1);
            }
            else
            {
                numStack.push(stoi(s));
            }
        }
        return numStack.top();
    }
};
// @lc code=end

