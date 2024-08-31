/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1)
        {
            return false;
        }
        stack<char> v;
        for(auto iter = s.begin(); iter != s.end(); ++iter)
        {
            if(*iter == '(')
            {
                v.push(')');
            }
            else if(*iter == '{')
            {
                v.push('}');
            }
            else if(*iter == '[')
            {
                v.push(']');
            }
            else
            {
                if(v.empty() || v.top() != *iter)
                {
                    return false;
                }
                v.pop();
            }
        }

        return v.empty();
    }
};
// @lc code=end

