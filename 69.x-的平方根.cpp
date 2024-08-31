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

        int left = 0;
        int right = x;
        int mid = (left + right) / 2;
        // 注意防止溢出!!!
        // 将 mid * mid 与 x 的比较转换为
        // x / mid 与 mid 的比较
        while (1)
        {
            if( x / mid == mid || mid == left || mid == right)
            {
                break;
            }
            else if(x / mid > mid)
            {
                left = mid;
                mid = (left + right) / 2;
            }
            else if(x / mid < mid)
            {
                right = mid;
                mid = (left + right) / 2;
            }
        }
        return mid;
    }
};
// @lc code=end

