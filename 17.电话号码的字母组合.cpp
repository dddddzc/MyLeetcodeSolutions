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

    void combination(string& digits, int i) {
        // 终止条件
        if (i == digits.size()) {
            res.push_back(s);
            return ;
        }

        // step1 : 遍历第 i 个字母
        for (auto& c : letterMap[digits[i] - '0']) {
            s += c;
            // 子问题 : 大于第 i 个字符的部分
            combination(digits, i + 1);
            // 回溯
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

