/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1) {
            return s.size();
        }

        int res = 0;
        int left = 0;
        unordered_set<char> uset{s[0]};

        for(int right = 1; right < s.size(); right++) {
            // 找到了重复元素,开始右移left
            while(uset.find(s[right]) != uset.end()) {
                uset.erase(s[left]);
                left++;
            }
            // 已经把left移到了正确的位置, 或者没有重复元素
            uset.insert(s[right]);
            res = max(res, right - left + 1);
        }

        return res;
    }
};
// @lc code=end

