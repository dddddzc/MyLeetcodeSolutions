/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        
        vector<int> res;
        // 全是字母,只需要26个字母的哈希计数
        vector<int> pCnt(26, 0), sCnt(26, 0);

        // 统计 p 中字母的哈希计数
        for (char& c : p) {
            pCnt[c - 'a']++;
        }
        
        // 定长滑窗
        for (int right = 0; right < s.size(); right++)
        {
            // 右端点字母进入窗口
            sCnt[s[right] - 'a']++;
            // 左端点 index
            int left = right - p.size() + 1;
            // 窗口长度不足
            if (left < 0) continue;

            // 窗口内字母计数相同
            if (sCnt == pCnt) res.push_back(left);
            // 左端点字母离开窗口
            sCnt[s[left] - 'a']--;
        }
        
        return res;
    }
};
// @lc code=end

