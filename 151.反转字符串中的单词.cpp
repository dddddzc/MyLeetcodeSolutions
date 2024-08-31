/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    void removeBlankSpaces(string& s)
    {
        int slow = 0;
        for(int fast = 0; fast < s.size(); )
        {
            if(s[fast] != ' ')
            {
                s[slow++] = s[fast++];
            }
            else
            {
                while(s[fast] == ' ')
                {
                    fast++;
                }
                // avoid the 0 in the head and tail
                if(slow != 0 && fast != s.size())
                {
                    s[slow++] = ' ';
                }
            }
        }
        s.resize(slow);
    }

    void reverseStr(string& s, int start, int end)
    {
        for(int i = start; i <= start + (end - start) / 2; ++i)
        {
            swap(s[i], s[end - i + start]);
        }
    }

    string reverseWords(string s) {
        removeBlankSpaces(s);
        reverseStr(s, 0, s.size() - 1);
        int left = 0;
        for(int right = 0; right < s.size(); ++right)
        {
            if(s[right] == ' ')
            {
                reverseStr(s, left, right - 1);
                left = right + 1;
            }
            if(right == s.size() - 1)
            {
                reverseStr(s, left, right);
            }
        }
        return s;
    }
};
// @lc code=end

