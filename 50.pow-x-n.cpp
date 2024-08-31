/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
        {
            return 1;
        }

        double res = 1;
        if (n > 0)
        {
            res = QuickPow(x, n);
        }
        else
        {
            res = 1 / QuickPow(x, n);
        }
        return res;
    }
    double QuickPow(double x, int N)
    {
        // N is a positive integer
        if(N == 0 || x == 1)
        {
            return 1;
        }
        double y = QuickPow(x, N/2);
        if (N % 2 == 0)
        {
            return y * y;
        }
        else
        {
            return y * y * x;
        }
    }
};
// @lc code=end