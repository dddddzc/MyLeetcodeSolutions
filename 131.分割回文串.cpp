/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> curr;

    bool isPalindrome(string s)
    {
        if(s.empty() || s.size() == 1) return true;
        int n = s.size();
        for(int i = 0; i <= n / 2; i++)
        {
            if(s[i] != s[n - i - 1]) return false;
        }
        return true;
    }

    void backtracking(string s)
    {
        if(s.empty())
        {
            res.push_back(curr);
            return ;
        }

        for(int cutIndex = 1; cutIndex <= s.size(); cutIndex++)
        {
            // [0, cutIndex)
            if(isPalindrome(s.substr(0, cutIndex)))
            {
                curr.push_back(s.substr(0, cutIndex));
                // [cutIndex, end)
                backtracking(s.substr(cutIndex));
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        if(s.empty()) return res;
        backtracking(s);
        return res;
    }
};
// @lc code=end

