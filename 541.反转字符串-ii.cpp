/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    void myReverse(string& s, int start, int end)
    {
        for(int i = start; i <= start + (end - start) / 2; ++i)
        {
            swap(s[i], s[end - i + start]);
        }
    }

    string reverseStr(string s, int k) {
        int n = s.size() - 1;
        for(int i = 0; i <= n; i += 2 * k)
        {
            if(n - i < k)
            {
                myReverse(s, i, n);
            }
            else
            {
                myReverse(s, i, i + k - 1);
            }
        }
        return s;
    }
};
// @lc code=end

