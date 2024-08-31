/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size() - 1;
        for(int i = 0; i <= n / 2; ++i)
        {
            swap(s[i], s[n - i]);
        }
    }
};
// @lc code=end

