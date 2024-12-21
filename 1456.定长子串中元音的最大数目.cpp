/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {        
        int res = 0, curRes = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // step1 : 入,下标 i 的元素进入窗口,更新局部统计量。
            if (isVowel(s[i])) curRes++;
            // 如果 i < k - 1, 重复step1
            if (i < k - 1) continue;
            // step2 : 更新全局统计量
            res = max(res, curRes);
            if (res == k) return k; // 剪枝优化
            
            // step3 : 下标为 i - k + 1 的元素离开窗口, 更新局部统计量。
            if (isVowel(s[i - k + 1])) curRes--;
        }
        return res;
    }
};
// @lc code=end

