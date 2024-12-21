/*
 * @lc app=leetcode.cn id=2063 lang=cpp
 *
 * [2063] 所有子字符串中的元音
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

    long long countVowels(string word) {
        if (word.empty()) return 0;
        if (word.size() == 1) return isVowel(word[0]);
        
        long long res = 0;
        res = isVowel(word[0]);

        for (int right = 1; right < word.size(); right++) {
            // step1 : right 进入窗口, 更新窗口状态
            if (isVowel(word[right])) {
                // 1 是当前的单个字母
                res += res + 2;
            } else {
                res += res;
            }
        }
        return res;
    }
};
// @lc code=end

