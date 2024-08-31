/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string newS;
        for(char c : s)
        {
            if(newS.empty() || newS.back() != c)
            {
                newS.push_back(c);
            }
            else
            {
                newS.pop_back();
            }
        }
        return newS;
    }
};
// @lc code=end

