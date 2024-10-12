/*
 * @lc app=leetcode.cn id=3158 lang=cpp
 *
 * [3158] 求出出现两次数字的 XOR 值
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res = 0;
        unsigned long visited = 0; // 第i位表示nums[i], 标记nums[i]是否出现过
        for (int& num : nums) {
            // visited右移num位,如果为1,说明是第2次访问,用ans与其异或
            if (visited >> num & 1) {
                res ^= num;
            } else {
            // 第1次访问,将visited的第num位改为1
                visited |= 1UL << num;
            }
        }
        return res;
    }
};
// @lc code=end

