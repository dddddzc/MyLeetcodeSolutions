/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <cstdint>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    // valid 记录 t 中的字符, 有或者没有
    vector<bool> valid(128, false);
    // freq 记录目前 t 中每个字符在 s 的滑动窗口中缺少的数量
    // 如果为正, 则说明还缺少；如果为负, 则说明有盈余。
    vector<int> freq(128, 0);
    for (int i = 0; i < t.length(); ++i) {
      valid[t[i]] = true;
      ++freq[t[i]];
    }

    // count 代表已经被包含的字符个数,重复的也会算
    int count = 0;
    // 分别代表最优解的left和length
    int min_left = -1, min_len = INT32_MAX;
    // 枚举 s 字串的右端点 right, 如果子串涵盖 t，就不断移动左端点 left
    // 直到不涵盖为止。 在移动过程中更新最短子串的左右端点。
    for (int left = 0, right = 0; right < s.length(); ++right) {
      // 当前 s[right] 非 valid, 直接跳过
      if (!valid[s[right]]) {
        continue;
      }

      // 把 right 位置的字符加入频率统计
      freq[s[right]]--;
      // 并检查是否补充了缺失的字符
      if (freq[s[right]] >= 0) {
        ++count;
      }

      // 在滑动窗口已包含t中全部字符的情况下
      while (count == t.length()) {
        // 更新全局变量 min_left 和 min_len
        if (right - left + 1 < min_len) {
          min_left = left;
          min_len = right - left + 1;
        }

        // 尝试右移left，在不影响结果的情况下寻找最短串。
        // 将left的字符移除频率统计,并检查t中对应字符是否重新缺失
        if (valid[s[left]]) {
          freq[s[left]]++;
          if (freq[s[left]] > 0) {
            --count;
          }
        }
        left++;
      }
    }
    return min_len == INT32_MAX ? "" : s.substr(min_left, min_len);
  }
};
// @lc code=end
