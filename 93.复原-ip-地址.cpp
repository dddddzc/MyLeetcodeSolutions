/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> res;
    string curr;

    bool isValid(const string& s)
    {
        if(s.empty() || s.size() > 3) return false;
        if(s == "0") return true;
        if(s[0] == '0') return false;
        if(stoi(s) < 0 || stoi(s) > 255) return false;
        return true;
    }

    void backtracking(string s, int depth)
    {
        if(depth == 3)
        {
            if(isValid(s))  res.push_back(curr + s);
            return ;
        }

        // 当前字符串长度小于3时也要考虑
        for(int i = 1; i <= s.size() && i <= 3; i++)
        {
            if(isValid(s.substr(0, i)))
            {
                curr += s.substr(0, i);
                curr += '.';
                backtracking(s.substr(i), depth + 1);
                for(int j = 0; j < i + 1; j++) curr.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if(s.empty()) return res;
        backtracking(s, 0);
        return res;
    }
};
// @lc code=end

