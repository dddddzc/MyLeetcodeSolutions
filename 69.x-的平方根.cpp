/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
        {
            return x;
        }

        // 使用 [left, right] 左闭右闭
        int left = 0;
        int right = x;
        int mid;
        // 防止溢出：将 mid * mid 与 x 的比较转换为 x / mid 与 mid 的比较
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if(mid == x / mid)
            {
                return mid;
            }
            else if(mid < x / mid)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        // 此处是对于 x 的平方根不是整数的情况
        // 例如 x = 6, 最后一次循环会得到 left = 3, right = 2
        // 例如 x = 8, 最后一次循环会得到 left = 3, right = 2
        // 然后不满足while条件, 跳出循环
        return right;
    }
};
// @lc code=end

