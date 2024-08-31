/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>
using namespace std;
class Solution {
public:
    int getSquared(int& n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sums;
        while(1)
        {
            int sum = getSquared(n);
            if(sum == 1)
            {
                return true;
            }

            if(sums.find(sum) != sums.end())
            {
                return false;
            }
            else
            {
                sums.insert(sum);
            }
            n = sum;
        }
    }
};
// @lc code=end

