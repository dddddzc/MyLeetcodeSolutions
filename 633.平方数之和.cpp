/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        if( isSquareNum(c) )
        {
            return true;
        }
        for(int i = 0; i <= c/2 ; ++i)
        {
            if(isSquareNum(c - i*i))
            {
                return true;
            }
        }
        return false;
    }

    bool isSquareNum(int x)
    {
        if(x == 0 || x == 1 || x == 4)
        {
            return true;
        }
        for(int i = 1; i <= x/2; ++i)
        {
            if(x / i == i)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

