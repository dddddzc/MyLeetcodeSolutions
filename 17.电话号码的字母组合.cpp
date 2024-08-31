/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    const string letterMap[10] = 
    {
        "", // 0
        "", // 1
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    vector<string> res; // 答案汇总
    string s = "";      // 存储单个答案

    void combination(string& digits, int idx)
    {
        // 结束条件:不是digits.size() - 1
        if(idx == digits.size()) 
        {
            res.push_back(s);
            return ;
        }

        // digits[idx] 是一个char,例如'2'
        string curr2str = letterMap[digits[idx] - '0'];

        for(int i = 0; i < curr2str.size(); i++)
        {
            s.push_back(curr2str[i]);
            combination(digits, idx + 1);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;

        combination(digits, 0);
        return res;
    }
};
// @lc code=end

