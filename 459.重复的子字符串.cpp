/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string s2 = s + s;
        s2.erase(s2.begin());
        s2.erase(s2.end() - 1);
        if(s2.find(s) != string::npos)
        {
            return true;
        }
        
        return false;
    }
};
// @lc code=end

